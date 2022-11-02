/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:29:51 by averon            #+#    #+#             */
/*   Updated: 2022/11/02 13:43:19 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			|| str[i] == ' ')
		{	
			g_exit_status = 1;
			return (0);
		}
		if (str[i] == '+' && str[i + 1] != '=')
		{
			g_exit_status = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

void	export_error(char *str)
{
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
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
			if (ft_strcmp(envp[j], envp[i + 1]) > 0)
			{
				tmp = envp[j];
				envp[j] = envp[i + 1];
				envp[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
