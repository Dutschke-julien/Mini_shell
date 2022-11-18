/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:47:40 by averon            #+#    #+#             */
/*   Updated: 2022/11/18 10:06:06 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_exec(t_core *mini, int i)
{
	input_split(mini);
	if (mini->cmd[0])
	{	
		mini->tab_tok = ft_split(mini->cmd[i], ' ');
		if (!exec_builtins_no_fork(mini))
			;
		else
		{
			pipex(mini);
			if (g_exit_status == 2 || g_exit_status == 3)
				g_exit_status = g_exit_status + 128;
		}
	}
}

void	exec_cmd_pipex(t_core *mini, int i)
{
	mini->tab_tok = ft_split(mini->cmd[i], ' ');
	if (exec_builtins_fork(mini) == 1)
	{
		mini->bin_no_path = ft_strdup(mini->tab_tok[0]);
		if (get_path(mini) == NULL)
		{
			printf("Bash: %s: no such file or directory\n", mini->bin_no_path);
			g_exit_status = 127;
		}
		else if (access(mini->tab_tok[0], F_OK) == -1
			&& mini->bin_no_path[0] != '/'
			&& strncmp(mini->bin_no_path, "./", 2) != 0
			&& ft_strchr(&mini->bin_no_path[1], '/') == NULL)
		{	
			g_exit_status = 127;
			printf("Bash: %s: command not found\n", mini->bin_no_path);
		}
		else if (execve(mini->tab_tok[0], mini->tab_tok, mini->envp) == -1)
			execve_message(mini);
	}
	ft_free(mini->tab_tok);
	exit(g_exit_status);
}

void	execve_message(t_core *mini)
{
	mini->bin_no_path = ft_strjoin("Bash: ", mini->bin_no_path);
	perror(mini->bin_no_path);
	if (errno == 20 || errno == 13)
		g_exit_status = 126;
	else
		g_exit_status = 127;
}

int	exec_builtins_no_fork(t_core *mini)
{
	place_space_in_tab(mini->tab_tok);
	if (ft_strcmp(mini->tab_tok[0], "cd") == 0)
		return (exec_cd(mini));
	else if (ft_strcmp(mini->tab_tok[0], "unset") == 0)
		return (exec_unset(mini));
	else if (ft_strcmp(mini->tab_tok[0], "exit") == 0)
		return (exec_exit(mini));
	else if (ft_strcmp(mini->tab_tok[0], "export") == 0 && mini->tab_tok[1])
		return (exec_export(mini));
	return (1);
}
// EXPORT AVEC ARGUMENT

int	exec_builtins_fork(t_core *mini)
{
	place_space_in_tab(mini->tab_tok);
	if (ft_strcmp(mini->tab_tok[0], "env") == 0)
		return (exec_env(mini));
	else if (ft_strcmp(mini->tab_tok[0], "echo") == 0)
		return (exec_echo(mini));
	else if (ft_strcmp(mini->tab_tok[0], "pwd") == 0)
		return (exec_pwd());
	else if (ft_strcmp(mini->tab_tok[0], "export") == 0 && !mini->tab_tok[1])
		return (exec_export(mini));
	return (1);
}
// EXPORT SANS ARGUMENT