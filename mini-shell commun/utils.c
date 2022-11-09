/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:37:54 by averon            #+#    #+#             */
/*   Updated: 2022/11/09 15:11:44 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(char *message)
{
	perror(message);
	exit(errno);
}

void	check_tab_char(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("check_tab <%s>\n", tab[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;	

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (0);
	}
	return (1);
}

int	is_occurence(char c)
{
	if (c == '<' || c == '>' || c == '$' || c == '"' || c == 39 || c == '|')
		return (1);
	else
		return (0);
}
