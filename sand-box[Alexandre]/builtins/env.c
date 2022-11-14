/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:16:45 by averon            #+#    #+#             */
/*   Updated: 2022/11/11 10:36:22 by averon           ###   ########.fr       */
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

char	**realloc_envp_unset(t_core *mini, size_t size)
{
	char	**new;
	size_t	i;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (mini->envp[i] && i < size)
	{
		new[i] = ft_strdup(mini->envp[i]);
		i++;
	}
	new[size] = 0;
	ft_free(mini->envp);
	return (new);
}
