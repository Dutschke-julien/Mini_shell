/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_all_symbol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:38:06 by jdutschk          #+#    #+#             */
/*   Updated: 2022/11/08 19:15:57 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace_all_symbol(char *str)
{
	int	i;

	i = 10;
	while (i--)
	{
		replace_symbol(str, '<');
		replace_symbol(str, '>');
	}
	replace_symbol2(str, '"');
	replace_symbol2(str, 39);
	if (is_odd(str, '"'))
		return (printf("erreur\n"));
	if (is_odd(str, 39))
		return (printf("erreur\n"));
	return (0);
}

void	replace_symbol(char *str, char symbol)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == symbol)
		{
				str[i] = ' ';
			while (str[i] && str[i] == ' ')
					i++;
				str[i - 1] = symbol;
		}
		else
			i++;
	}
}

void	replace_symbol2(char *str, char c)
{
	unsigned int	i;
	unsigned int	cmpt;

	i = 0;
	cmpt = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			cmpt++;
			if (cmpt % 2 == 0)
			{
			str[i - 1] = c;
				str[i] = ' ';
			}
		}
		i++;
	}
}

int	is_odd(char *str, char c)
{
	unsigned int	i;
	unsigned int	cmpt;

	cmpt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			cmpt++;
		i++;
	}
	if (cmpt % 2)
		return (1);
	return (0);
}
