/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:20:14 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/13 20:44:50 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_tokens(char *str)
{
	int	i;
	int	cmpt;

	cmpt = 0;
	i = 0;
	while (str[i])
	{
		if (is_occurence(str[i]))
			cmpt++;
		i++;
	}
	return (cmpt);
}

int	is_occurence(char c)
{
	if (c == '<' || c == '>' || c == '$' || c == '"' || c == 39 || c == '|')
		return (1);
	else
		return (0);
}

char	*cmd_with_space(char *str, int i, int j)
{
	char	*s1;

	s1 = malloc(sizeof(char) * ft_strlen(str) + get_tokens(str) + 1);
	while (str[i])
	{
		if (is_occurence(str[i]))
		{
				s1[j] = ' ';
				j++;
				s1[j] = str[i];
				i++;
				j++;
		}
		else
		{
			s1[j] = str[i];
			j++;
			i++;
		}
	}
	s1[j] = '\0';
	//add free(str)
	return (s1);
}

char	*update_input(char *str, int i, int j)
{
	char	*s1;

	str = cmd_with_space(str, 0, 0);
	s1 = malloc(sizeof(char) * ft_strlen(str) + cmpt_this(str, '|') + 1);
	 while (str[i])
	{
		if (str[i] == '|')
		{
				s1[j] = str[i];
				i++;
				j++;
				s1[j] = ' ';
				j++;
		}
		else
		{
			s1[j] = str[i];
			j++;
			i++;
		}
	}
	s1[j] = '\0';
	//add free(str)
	return (s1);
}
