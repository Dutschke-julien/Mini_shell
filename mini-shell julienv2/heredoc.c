/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:08:53 by averon            #+#    #+#             */
/*   Updated: 2022/10/19 15:00:03 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(char *name, t_core *mini)
{
	int		fd;

	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	heredoc_loop(ft_strdup(name), fd, mini);
}

void	heredoc_loop(char *limiter, int fd, t_core *mini)
{
	char	*line;
	int		size;

	signal_hd_loop();
	size = ft_strlen(limiter);
	while (1)
	{
		line = readline("> ");
		if (!line || (!ft_strncmp(limiter, line, size) && !line[size]))
		{	
			close(fd);
			if (mini->tab_tok[1] && strcmp(mini->tab_tok[1], "cat") == 0)
				heredoc_cat(limiter);
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	free(limiter);
}

void	heredoc_cat(char *limiter)
{	
	int		fd_limiter;
	char	*line_limiter;

	fd_limiter = open(limiter, O_RDONLY);
	line_limiter = get_next_line(fd_limiter);
	printf("%s", line_limiter);
	while (line_limiter)
	{	
		line_limiter = get_next_line(fd_limiter);
		if (line_limiter)
			printf("%s", line_limiter);
	}
	close (fd_limiter);
}
