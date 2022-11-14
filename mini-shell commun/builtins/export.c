/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:08:24 by averon            #+#    #+#             */
/*   Updated: 2022/11/10 16:35:35 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_export(t_core *mini)
{
	g_exit_status = 0;
	if (mini->tab_tok[0] && !mini->tab_tok[1])
	{
		env_sort(mini->envp);
		export_print(mini->envp);
	}
	else if (mini->tab_tok[1] && is_valid_var_name(mini->tab_tok[1]))
	{	
		if (is_in_env(mini->envp, mini->tab_tok[1]) == 0)
			export_add_variable(mini, mini->tab_tok[1]);
		else
			export_change_value(mini->envp, mini->tab_tok[1]);
	}
	else
		export_error(mini->tab_tok[1]);
	return (0);
}

void	export_print(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		printf("declare -x %s\n", envp[i]);
		i++;
	}
}

char	**export_add_variable(t_core *mini, char *str)
{	
	size_t	n;

	n = nbvar_env(mini->envp);
	if (is_in_env(mini->envp, str) == 0)
		mini->envp = new_envp_export(mini, n);
	return (mini->envp);
}

void	export_change_value(char **envp, char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (str)
		while (str[len] != '=' && str[len] != 0)
			len++;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], str, len + 1))
		{	
			free (envp[i]);
			envp[i] = strdup(str);
		}
		i++;
	}
}

char	**new_envp_export(t_core *mini, size_t size)
{
	char	**new;
	size_t	i;

	new = (char **)malloc(sizeof(char *) * (size + 1 + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (mini->envp[i] && i < (size))
	{
		new[i] = ft_strdup(mini->envp[i]);
		i++;
	}
	new[i++] = ft_strdup(mini->tab_tok[1]);
	new[i++] = 0;
	ft_free(mini->envp);
	return (new);
}
