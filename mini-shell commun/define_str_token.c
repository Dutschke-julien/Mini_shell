/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_str_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:07:29 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/10 13:59:22 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*define_str_token(char *str)
{
	char	*s1;

	s1 = ft_calloc(ft_strlen(str) + 2, 1);
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

	s1 = ft_calloc(ft_strlen(str) + 2, 1);
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

char	*define_str_token3(char *str)
{
	char	*s1;

	s1 = ft_calloc(ft_strlen(str) + 2, 1);
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
	char	*temp;

	s1 = NULL;
	temp = ft_strdup(str);
	if (!temp)
	{	
		free(str);
		return (NULL);
	}
	if (temp[0] != 39 && temp[0] != '<' && temp[0] != '>' && temp[0] != '"'
		&& temp[0] != '$' && temp[0] != '|')
		s1 = ft_strjoin(temp, "0");
	else
		s1 = ft_strdup(temp);
	free(str);
	free(temp);
	return (s1);
}

void	change_pipe_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			str[i] = 4;
		i++;
	}
}
