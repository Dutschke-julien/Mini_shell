/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:08:24 by averon            #+#    #+#             */
/*   Updated: 2022/10/11 10:27:58 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_export(t_core *mini)
{
	if (mini->tab_tok[0] && !mini->tab_tok[1])
	{
		env_sort(mini->envp);
		export_print(mini->envp);
	}
	else if (mini->tab_tok[1] && is_valid_var_name(mini->tab_tok[1]))
		export_add_variable(mini, mini->tab_tok[1]);
	return (0);
}


/*int export_check(char **str)
{

}*/

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


int	is_in_env(char **envp, char *str)
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
		if (!ft_strncmp(envp[i], str, len))
			return (1);
		i++;
	}
	return (0);
}

void	env_sort(char **envp)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (envp[j])
	{
		i = j;
		while (envp[i + 1])
		{
			if (ft_strcmp(envp[i], envp[i + 1]) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[i + 1];
				envp[i + 1] = tmp;
			}
			i++;
		}
		j++;
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

/*export_change_value(char **envp)
{

}*/

int	is_valid_var_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '-' || str[i] == '.' || str[i] == '{' || str[i] == '}'
			|| str[i] == '*' || str[i] == '#' || str[i] == '@' || str[i] == '!'
			|| str[i] == '^' || str[i] == '~' || str[i] == 39 || str[i] == '|'
			|| str[i] == 34 || str[i] == 36 || str[i] == ';' || str[i] == '&'
			|| str[i] == '=' || str[i] == ' ')
		{	
			g_g.exit_status = 1;
			return (0);
		}
		if (str[i] == '+' && str[i + 1] != '=')
		{
			g_g.exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

char	**new_envp_export(t_core *mini, size_t size)
{
	char	**new;
	size_t	i;

	new = (char **)malloc(sizeof(char *) * (size + 1 + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (mini->envp[i] && i < (size - 1))
	{
		new[i] = ft_strdup(mini->envp[i]);
		i++;
	}
	new[i] = ft_strdup(mini->tab_tok[1]);
	new[size] = 0;
	ft_free(mini->envp);
	return (new);
}


