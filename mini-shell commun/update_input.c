/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:21:15 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/09 14:24:41 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free(str);
	return (s1);
}

void	change_spc(char *str, char first, char second)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] != first && str[i])
			i++;
		if (str[i])
			i++;
		while (str[i] != second && str[i])
		{
			if (str[i] == ' ')
				str[i] = 4;
			if (str[i] == '|')
				str[i] = 5;
			if (str[i] == '<')
				str[i] = 6;
			if (str[i] == '>')
				str[i] = 7;
			i++;
		}
		if (str[i])
			i++;
	}
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
	free(str);
	return (s1);
}

int	cmpt_this(char *str, char c)
{
	int	i;
	int	cmpt;

	i = 0;
	cmpt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cmpt++;
		i++;
	}
	return (cmpt);
}

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
