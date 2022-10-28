/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:08:53 by averon            #+#    #+#             */
/*   Updated: 2022/10/28 13:48:39 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(char *name)
{
	int		fd;

	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	heredoc_loop(ft_strdup(name), fd);
	return (fd);
}

int	heredoc_loop(char *limiter, int fd)
{
	char	*line;
	int		size;

	size = ft_strlen(limiter);
	while (1)
	{
		signals_run(1);
		line = readline("> ");
		if (!line || (!ft_strncmp(limiter, line, size) && !line[size]))
		{	
			close(fd);
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(limiter);
	return (fd);
}
