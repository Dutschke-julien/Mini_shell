/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:52:36 by averon            #+#    #+#             */
/*   Updated: 2022/09/09 16:24:31 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nbvar_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	//ft_printf("nombre de var env: %d\n", i);
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
		//ft_printf("nom var env: %s\n", envp[i]);
		i++;
	}
	return (envp);
}


