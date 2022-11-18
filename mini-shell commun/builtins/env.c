/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:16:45 by averon            #+#    #+#             */
/*   Updated: 2022/11/18 10:01:56 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_env(t_core *mini)
{
	int	i;

	i = 0;
	while (mini->envp[i])
	{
		ft_printf("%s\n", mini->envp[i]);
		i++;
	}
	g_exit_status = 0;
	return (0);
}
