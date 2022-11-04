/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_token_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:06:22 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/03 14:44:31 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*transform_str_dollar2(char **tab, int *space_data)
{
	int		i;
	char	*new_string;

	i = 0;
	new_string = ft_calloc(2, 1);
	while (space_data[i])
	{
		new_string = ft_strjoin(new_string, tab[i]);
		new_string = add_space_str_dollar(new_string, space_data[i]);
		i++;
	}
	while (tab[i])
	{
		new_string = ft_strjoin(new_string, tab[i]);
		i++;
	}
	return (new_string);
}

char	*add_space_str_dollar(char *str, int space)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = malloc(ft_strlen(str) + space + 1);
	while (str[i])
	{
		s1[i] = str[i];
		i++;
	}
	while (space--)
	{
		s1[i] = ' ';
		i++;
	}
	s1[i] = '\0';
	free(str);
	return (s1);
}
