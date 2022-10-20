/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:05:33 by averon            #+#    #+#             */
/*   Updated: 2022/10/19 15:18:04 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]))
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void    ft_putendl_fd(char *s, int fd)
{
        int     i;

        i = 0;
        while (s[i])
                i++;
        write (fd, s, i);
        write (fd, "\n", 1);
}

int main()
{
	char* file;
	char* line;
	int		fd;
	int 	pid;

	file = "file";
	fd = open(file , O_CREAT | O_TRUNC | O_WRONLY, 0777);

	while (1)
	{
		line = readline("> ");
		ft_putendl_fd(line, fd);
		if (ft_strncmp(line, "stop", 4) == 0)
		{	
			free(line);
			break;
		}
	}
	close(fd);
	return (0);
}


