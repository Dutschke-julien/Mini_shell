/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:12:06 by averon            #+#    #+#             */
/*   Updated: 2022/11/11 11:24:05 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_exit(t_core *mini)
{
	if (mini->tab_tok[1] && !ft_isnumber(mini->tab_tok[1]))
	{
		numeric_arg_req(mini);
		g_exit_status = 255;
		free_minishell(mini);
		exit (255);
	}
	else if (mini->tab_tok[1] && mini->tab_tok[2])
	{	
		too_many_args();
		g_exit_status = 1;
		return (0);
	}
	else if (mini->tab_tok[1] && ft_isnumber(mini->tab_tok[1]))
		g_exit_status = (ft_atoi(mini->tab_tok[1]) % 256);
	ft_putstr_fd("exit\n", 2);
	free_minishell(mini);
	exit(g_exit_status);
	return (0);
}

int	too_many_args(void)
{
	ft_putendl_fd("Minishell: exit: too many arguments", 2);
	return (0);
}

void	numeric_arg_req(t_core *mini)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(mini->tab_tok[1], 2);
	ft_putendl_fd(": numeric argument required", 2);
}
