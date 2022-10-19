/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:16:51 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/19 13:01:52 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_str_space_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		replace_str_space(tab[i]);
		i++;
	}
}

void	replace_str_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 4)
			str[i] = ' ';
		i++;
	}
}

void	define_tab_tokens(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab[i] = define_str_token(tab[i]);
		tab[i] = define_str_token2(tab[i]);
		tab[i] = define_str_token3(tab[i]);
		tab[i] = define_str_token4(tab[i]);
		if (tab[i][ft_strlen(tab[i]) - 1] == '6')
			change_pipe_in_str(tab[i]);
		i++;
	}
}

char	*define_str_token(char *str)
{
	char	*s1;

	s1 = malloc(ft_strlen(str) + 1);
	s1 = ft_strcpy(s1, str);
	if (s1[0] == '<' && s1[1] == '<')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '3';
	}
	else if (s1[0] == '<')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '1';
	}
	else if (s1[0] == '"')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '6';
	}
	free(str);
	return (s1);
}

char	*define_str_token2(char *str)
{
	char	*s1;

	s1 = malloc(ft_strlen(str) + 1);
	s1 = ft_strcpy(s1, str);
	if (s1[0] == '>' && s1[1] == '>')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '4';
	}
	else if (s1[0] == '>')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '2';
	}
	else if (s1[0] == '>')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '2';
	}
	free(str);
	return (s1);
}
