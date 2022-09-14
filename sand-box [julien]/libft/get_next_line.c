/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:34:35 by alexandreve       #+#    #+#             */
/*   Updated: 2022/04/29 11:59:29 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char	*ft_read_and_cat(int fd, char *str_save, char *temp, char *buff)
{
	int		ret_read;

	ret_read = 1;
	while (ret_read != 0)
	{
		ret_read = read(fd, buff, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret_read] = '\0';
		temp = str_save;
		if (!temp)
		{
			temp = malloc(sizeof(char) * 1);
			temp [0] = '\0';
		}
		str_save = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(str_save, '\n'))
			break ;
	}
	free(buff);
	return (str_save);
}

static char	*ft_make_line(char *str_save)
{
	char	*line;
	int		i;	

	i = 0;
	if (!str_save[i])
		return (NULL);
	while (str_save[i] != '\n' && str_save[i] != '\0' )
		i++;
	line = malloc(sizeof(*line) * i + 2);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str_save[i] != '\n' && str_save[i] != '\0')
	{	
		line[i] = str_save[i];
		i++;
	}
	if (str_save[i] == '\n')
	{	
		line[i] = str_save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_cut_and_save(char *str_save)
{
	unsigned long	i;
	unsigned long	x;
	char			*str;

	i = 0;
	x = ft_strlen (str_save);
	while (str_save[i] && str_save[i] != '\n')
		i++;
	if (str_save[i] == '\0')
	{
		free(str_save);
		return (NULL);
	}
	str = malloc (sizeof(*str) * (x - i) + 1);
	if (str == NULL)
		return (NULL);
	i++;
	x = 0;
	while (str_save[i])
		str[x++] = str_save[i++];
	str[x] = '\0';
	free(str_save);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	char		*buff;
	static char	*str_save;

	temp = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buff = malloc(sizeof(*buff) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	str_save = ft_read_and_cat(fd, str_save, temp, buff);
	if (!str_save)
		return (NULL);
	line = ft_make_line(str_save);
	str_save = ft_cut_and_save(str_save);
	return (line);
}
