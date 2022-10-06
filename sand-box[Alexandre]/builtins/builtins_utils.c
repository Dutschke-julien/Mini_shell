/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:16:37 by averon            #+#    #+#             */
/*   Updated: 2022/10/06 14:03:41 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Checks if the command is a subject defined command (builtin).
 *
 * @param cmd The command to be checked.
 * @return int 1 if the command is a subject defined command, 0 otherwise.
 */
int	is_builtin(t_core *mini)
{
	if (!ft_strncmp(mini->tab_tok[0], "echo\0", 5))
		return (1);
	else if (!ft_strncmp(mini->tab_tok[0], "pwd\0", 4))
		return (1);
	else if (!ft_strncmp(mini->tab_tok[0], "cd\0", 3))
		return (1);
	else if (!ft_strncmp(mini->tab_tok[0], "export\0", 7))
		return (1);
	else if (!ft_strncmp(mini->tab_tok[0], "unset\0", 6))
		return (1);
	else if (!ft_strncmp(mini->tab_tok[0], "env\0", 4))
		return (1);
	else if (!ft_strncmp(mini->tab_tok[0], "exit\0", 5))
		return (1);
	return (0);
}

/**
 * @brief Some builtins need a child process to run. This function checks if a
 * builtin needs a child process. If it does, it returns 1. Otherwise, it
 * returns 0. The builtins that need a child process are: cd, exit, unset.
 *
 * @param command The command to execute.
 * @return int 1 if the command needs a child process, 0 otherwise.
 */
int	is_forked_command(t_core *mini)
{
	if (!ft_strncmp(mini->tab_tok[0], "cd\0", 3)
		|| !ft_strncmp(mini->tab_tok[0], "unset\0", 6)
		|| !ft_strncmp(mini->tab_tok[0], "exit\0", 5))
	{
		exec_builtins_parent(mini);
		return (0);
	}
	else if (!ft_strncmp(mini->tab_tok[0], "export\0", 7)
		&& mini->tab_tok[1])
	{
		exec_builtins_parent(mini);
		return (0);
	}
	return (1);
}