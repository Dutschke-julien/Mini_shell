/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:47:40 by averon            #+#    #+#             */
/*   Updated: 2022/10/28 16:06:08 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd_pipex(t_core *mini, int i)
{
	mini->tab_tok = ft_split(mini->cmd[i], ' ');
	if (exec_builtins_all(mini) == 1)
	{
		get_path(mini);
		if (execve(mini->tab_tok[0], mini->tab_tok, NULL) == -1)
			perror("pb with execve\n");
	}
	ft_free(mini->tab_tok);
	exit(0);
}

int	exec_builtins_all(t_core *mini)
{
	if (ft_strcmp(mini->tab_tok[0], "cd") == 0)
		return (exec_cd(mini));
	else if (ft_strcmp(mini->tab_tok[0], "echo") == 0)
		return (exec_echo(mini));
	else if (ft_strcmp(mini->tab_tok[0], "env") == 0)
		return (exec_env(mini));
	else if (ft_strcmp(mini->tab_tok[0], "exit") == 0)
		return (exec_exit(mini));
	else if (ft_strcmp(mini->tab_tok[0], "export") == 0)
		return (exec_export(mini));
	else if (ft_strcmp(mini->tab_tok[0], "pwd") == 0)
		return (exec_pwd(mini));
	else if (ft_strcmp(mini->tab_tok[0], "unset") == 0)
		return (exec_unset(mini));
	return (1);
}
