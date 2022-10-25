/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:16:37 by averon            #+#    #+#             */
/*   Updated: 2022/10/11 10:26:31 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief verifie si la commande est un builtin.
 * @param tab_tok[0]: La commande a verifier.
 * @return int 1 si la commande est un builtin, 0 sinon.
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

// VERIFIER UTILITE
int	is_forked_command(t_core *mini)
{
	if (!ft_strncmp(mini->tab_tok[0], "cd\0", 3)
		|| !ft_strncmp(mini->tab_tok[0], "unset\0", 6)
		|| !ft_strncmp(mini->tab_tok[0], "exit\0", 5))
	{
		return (1);
	}
	else if (!ft_strncmp(mini->tab_tok[0], "export\0", 7)
		&& mini->tab_tok[1])
	{
		return (1);
	}
	return (0);
}