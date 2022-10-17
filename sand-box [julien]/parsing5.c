/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:59:05 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/17 18:05:14 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*define_str_token3(char *str)
{
	char	*s1;

	s1 = malloc(ft_strlen(str) + 1);
	s1 = ft_strcpy(s1, str);
	if (s1[0] == 39)
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '7';
	}
	else if (s1[0] == '$')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '5';
	}
	else if (s1[0] == '|')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '8';
	}
	free(str);
	return (s1);
}

char	*define_str_token4(char *str)
{
	char	*s1;

	s1 = malloc(ft_strlen(str) + 1);
	s1 = ft_strcpy(s1, str);
	if (s1[0] != 39 && s1[0] != '<' && s1[0] != '>' && s1[0] != '"'
		&& s1[0] != '$' && s1[0] != '|')
	{
		s1[ft_strlen(s1) + 1] = '\0';
		s1[ft_strlen(s1)] = '0';
	}
	free(str);
	return (s1);
}
