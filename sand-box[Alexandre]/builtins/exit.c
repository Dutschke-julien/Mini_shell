/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:12:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/05 18:20:33 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Cette commande sort du shell actuel avec un statut donné. 
 * S'il est omis, utilisation du statut de sortie de la derniere cde lancee.
 * 0 (zero) signifie succes, non-zero signifies echec. Il est donc necessaire
 * de verifier si la cde recoit um parametre numerique. Sinon, une erreur
 * "exit: numeric argument required" dera impri;e sur STDERR et le satut de
 * sortie sera 1. Si un arg. numerique est entre, il faut verifer si le nombre
 * d'args et valide. Si ok, om quite le shell avec le statut exit donné. 
 * sinon, om imprime le message d'erreur et on exit avec le statut 1.
 * @param: The exec list of parameters.
 * @return: int 0 if success.
 */

int	exec_exit(t_core *mini)
{
	if (mini->tab_tok[1] && mini->tab_tok[2])
	{	
		too_many_args();
		return (0);
	}
	else if (mini->tab_tok[1] && ft_isnumber(mini->tab_tok[1]))
		g_exit_status = ft_atoi(mini->tab_tok[1]);
	else if (mini->tab_tok[1] && !ft_isnumber(mini->tab_tok[1]))
	{
		numeric_arg_req(mini);
		return (0);
	}
	g_exit_status = ft_atoi(mini->tab_tok[1]);
	ft_putstr_fd("exit\n", 2);
	free_minishell();
	exit(g_exit_status);
	return (0);
}

/**
 * @brief fonction auxiliaire de la fonction exit.
 * Elle envoie sur STDERR le message "exit: too many arguments" et set le
 * exit status à 1.
 */

int	too_many_args(void)
{
	ft_putendl_fd("Minishell: exit: too many arguments", 2);
	g_exit_status = 1;
	return (0);
}

/**
 * @brief fonction auxiliaire de la fonction exit.
 * Elle envoie sur STDERR le message "numberic argument required".
 * Elle set the exit status à 2.
 * @return int 1 car cette fonction sort du shell.
 */

int	numeric_arg_req(t_core *mini)
{
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(mini->tab_tok[1], 2);
	ft_putendl_fd(": numeric argument required", 2);
	exit(2);
	return (1);
}
