/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:24:00 by averon            #+#    #+#             */
/*   Updated: 2022/10/31 11:15:54 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell(t_core *mini)
{
	if (mini->envp)
		ft_free(mini->envp);
	if (mini->cmd)
		ft_free(mini->cmd);
	if (mini->tab_tok)
		ft_free(mini->tab_tok);
	if (mini->path_tab)
		ft_free(mini->path_tab);
	if (mini)
		free(mini);
	rl_clear_history();
}
