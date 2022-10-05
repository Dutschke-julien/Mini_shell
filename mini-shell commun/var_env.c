/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:52:36 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 11:50:54 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nbvar_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**init_env(char **env)
{
	char	**envp;
	int		i;
	int		n;

	i = 0;
	n = nbvar_env(env);
	envp = malloc(sizeof(char *) * (n + 1));
	if (envp == NULL)
		return (NULL);
	while (env[i])
	{
		envp[i] = strdup(env[i]);
		i++;
	}
	return (envp);
}

char	**realloc_envp(t_core *mini, size_t size)
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
