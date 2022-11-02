/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:47:40 by averon            #+#    #+#             */
/*   Updated: 2022/11/02 09:49:59 by averon           ###   ########.fr       */
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
			ft_free(mini->tab_tok);
		else
			pipex(mini);
	}
}

void	exec_cmd_pipex(t_core *mini, int i)
{
	char	*str;

	str = NULL;
	mini->tab_tok = ft_split(mini->cmd[i], ' ');
	if (exec_builtins_fork(mini) == 1)
	{
		str = ft_strdup(mini->tab_tok[0]);
		get_path(mini);
		if (execve(mini->tab_tok[0], mini->tab_tok, NULL) == -1)
		{	
			str = ft_strjoin("Bash: ", str);
			perror(str);
		}
	}
	free(str);
	ft_free(mini->tab_tok);
	exit(0);
}

int	exec_builtins_no_fork(t_core *mini)
{
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