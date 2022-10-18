/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:08:53 by averon            #+#    #+#             */
/*   Updated: 2022/10/17 12:19:02 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc(char *name)
{
	int		fd[2];
	int		pid;
	int		status;

	if (pipe(fd) == -1)
		return (heredoc_error(NULL));
	pid = fork();
	if (pid == -1)
		return (heredoc_error(NULL));
	if (!pid)
	{
		close(fd[0]);
		heredoc_loop(ft_strdup(name), &fd[1]);
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (heredoc_error(fd));
	return (fd[0]);
}

void	heredoc_loop(char *limiter, int *file_descriptor)
{
	char	*line;
	int		size;

	signal_hd_loop();
	line = readline("> ");
	size = ft_strlen(limiter);
	while (1)
	{
		if (!line || (!ft_strncmp(limiter, line, size) && !line[size]))
			break ;
		ft_putendl_fd(line, *file_descriptor);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(*file_descriptor);
	free(limiter);
	exit(0);
}

int	heredoc_error(int *fd)
{
	if (fd)
		close(fd[0]);
	else
	{
		//free_minishell();
		exit(-54);
	}
	return (-3);
}