/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:22:35 by averon            #+#    #+#             */
/*   Updated: 2022/11/15 15:10:01 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipex(t_core *mini)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i <= mini->nb_pipe)
	{
		pipe(mini->tube);
		pid = fork();
		signals_run(2);
		if (pid == 0)
		{
			dup2(mini->fd_input, STDIN_FILENO);
			if (i < mini->nb_pipe)
				dup2(mini->tube[1], STDOUT_FILENO);
			else
			{
				mini->tube[1] = mini->fd_output;
				dup2(mini->tube[1], STDOUT_FILENO);
			}
			ft_child_process(mini, i);
		}
		else
			ft_parent_process(mini->tube, &mini->fd_input, pid);
		i++;
	}
}

void	ft_child_process(t_core *mini, int i)
{
	close(mini->tube[0]);
	exec_cmd_pipex(mini, i);
}

void	ft_parent_process(int *tube, int *fd, pid_t pid)
{
	close(tube[1]);
	*fd = tube[0];
	waitpid(pid, &g_exit_status, WUNTRACED);
	status_child();
}

void	status_child(void)
{
	if (WIFEXITED(g_exit_status))
		g_exit_status = WEXITSTATUS(g_exit_status);
}
