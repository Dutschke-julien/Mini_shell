/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:52:36 by averon            #+#    #+#             */
/*   Updated: 2022/11/16 17:33:06 by averon           ###   ########.fr       */
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
		envp[i] = ft_strdup(env[i]);
		i++;
	}
	return (envp);
}

int	is_in_env(char **envp, char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (str)
		while (str[len] != '=' && str[len] != 0)
			len++;
	if (str[0] == '\0')
		return (1);
	if (str[0] == '?' && str[1] == '\0')
		return (1);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], str, len)
			&& (envp[i][len] == '=' || !envp[i][len]))
			return (1);
		i++;
	}
	return (0);
}
