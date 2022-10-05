/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:30:25 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 13:06:32 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// attention: unset fonctionne avec plusieurs variables

// exec_unset mets à zero la ligne dans mini->envp

int	exec_unset(t_core *mini)
{
	int	j;
	int x;
	int	len;

	j = 0;
	x = 1;
	while (mini->tab_tok[x])
	{
		len = ft_strlen(mini->tab_tok[x]);
		while (mini->envp[j] 
			&& ft_strnstr(mini->envp[j], mini->tab_tok[x], len) == 0)
			j++;
		if (mini->envp[j] != NULL)
			mini->envp[j][0] = 0;
		new_envp_unset(mini, j);
		x++;
	}
	return (0);
}

// exec_unset supprime la ligne vide dans mini->envp 
//(avec realloc du tableau plus petit)

char	**new_envp_unset(t_core *mini, int index)
{
	char	*temp;
	size_t	n;
	int		j;

	j = index;
	n = nbvar_env(mini->envp);
	while (mini->envp[j + 1])
	{
		temp = ft_strdup(mini->envp[j + 1]);
		free (mini->envp[j]);
		mini->envp[j] = temp;
		j++;
	}
	mini->envp = realloc_envp(mini, n - 1);
	return (mini->envp);
}
