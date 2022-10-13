/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanse_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:20:31 by averon            #+#    #+#             */
/*   Updated: 2022/10/13 10:03:51 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Si le '$' est suivi par:
	- '?', renvoyer le statut de sortie de la derniere cde exec. 
	- une var_env valide, le shell affiche la valeur de la variable à la place.
	- un chiffre ou une var_env invalide, pas de reponse du shell.	
*/

int	expanse_dollar(char **envp, char *str)
{
	int		i;
	char	*dollar_char;

	i = 0;
	if (str[i] == '$' && str[i + 1] == '?')
	{
		printf("%d", g_exit_status);
		return (1);
	}	
	else if (str[i] == '$' && str[i + 1] != '?')
	{
		dollar_char = dollar_is_in_env(envp, str);
		if (dollar_char)
		{	
			print_env(envp, dollar_char);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

char	*dollar_is_in_env(char **envp, char *str)
{
	char	*dollar_char;

	dollar_char = ft_strdup(++str);
	if (is_in_env(envp, dollar_char))
		return (dollar_char);
	else
		return (0);
}

void	print_env(char **envp, char *dollar_char)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (dollar_char)
	{	
		while (dollar_char[len] != '=' && dollar_char[len] != 0)
			len++;
	}
	dollar_char = ft_strjoin(dollar_char, "=");
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], dollar_char, len + 1))
			printf("%s", &envp[i][len + 1]);
		i++;
	}
}
