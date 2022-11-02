/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/11/02 17:46:50 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_str_token(char **tab, char **env)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][ft_strlen(tab[i]) - 1] == '5')
			tab[i] = transforming_into_six(tab[i]);
		if (tab[i][ft_strlen(tab[i]) - 1] == '6')
			change_dollar_in_str(tab[i], env);
		i++;
	}
}

/*															*/
void	change_dollar_in_str(char *str, char **env)
{
	int	i;
	int	i_tab;
	int	cmpt_space;
	int	*data_space;

	i = 0;
	i_tab = 0;
	data_space = ft_calloc(25, sizeof(int));
	while (str[i])
	{
		cmpt_space = 0;
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
			{
				cmpt_space++;
				i++;
			}
			data_space[i_tab] = cmpt_space;
			i_tab++;
		}
		i++;
	}
	replace_cote(str);
	str = transform_str_dollar(ft_split(str, ' '), data_space, env);
}

char	*transform_str_dollar(char **tab, int *space_data, char **env)
{
	char	*s1;
	int		i;
	(void)space_data;
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '$')
		{
			if (is_in_env(env, &tab[i][1]))
			{
				replace_str_by_env(tab[i], env);	
			}
			else
				delete_case(tab, i);
		}
		i++;
	}
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	s1 = NULL;
	return (s1);
}

void	replace_str_by_env(char *str, char **env)
{
	(void)env;
	ft_strcpy(str, getenv(&str[1]));
	return ;
}

char	*transforming_into_six(char *str)
{
	int		i;	
	char	*s1;

	s1 = ft_calloc(1, (ft_strlen(str) + 5));
	i = 0;
	s1[0] = '"';
	while (str[i])
	{
		s1[i + 1] = str[i];
		i++;
	}
	s1[i] = ' ';
	s1[i + 1] = '"';
	s1[i + 2] = '6';
	free (str);
	return (s1);
}
