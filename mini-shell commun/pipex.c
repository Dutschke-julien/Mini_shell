/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:22:35 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 19:18:42 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipex(t_core *mini)
{
	pid_t	pid;
	int		j;
	int		fd;

	j = 0;
	fd = 0;
	while (j <= mini->nb_pipe)
	{
		pipe(mini->tube);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd, STDIN_FILENO);
			if (j < mini->nb_pipe)
				dup2(mini->tube[1], STDOUT_FILENO);
			ft_child_process(mini, j);
		}
		else
			ft_parent_process(mini->tube, &fd);
		j++;
	}
}

void	ft_child_process(t_core *mini, int i)
{
	close(mini->tube[0]);
	exec_cmd(mini, i);
}

void	ft_parent_process(int *tube, int *fd)
{
	close(tube[1]);
	*fd = tube[0];
	wait(NULL);
	//ft_printf("le fils a fini\n\n");
}
