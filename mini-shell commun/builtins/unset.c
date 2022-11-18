/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:30:25 by averon            #+#    #+#             */
/*   Updated: 2022/11/18 10:06:58 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_unset(t_core *mini)
{
	int	j;
	int	len;

	j = 0;
	while (mini->tab_tok[1])
	{
		if (!is_in_env(mini->envp, mini->tab_tok[1]))
			return (0);
		len = ft_strlen(mini->tab_tok[1]);
		while (mini->envp[j]
			&& ft_strnstr(mini->envp[j], mini->tab_tok[1], len) == 0)
			j++;
		if (mini->envp[j] != NULL)
			mini->envp = realloc_envp_unset(mini, j);
	}
	g_exit_status = 0;
	return (0);
}

char	**realloc_envp_unset(t_core *mini, int index)
{
	char	**new;
	int		size;
	int		i;
	int		j;

	size = nbvar_env(mini->envp);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (mini->envp[i] && i < size && mini->envp[j])
	{
		if (i != index)
			new[i] = ft_strdup(mini->envp[j]);
		else
			new[i] = ft_strdup(mini->envp[++j]);
		i++;
		j++;
	}
	ft_free(mini->envp);
	return (new);
}
