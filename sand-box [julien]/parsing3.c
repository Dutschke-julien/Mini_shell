/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:21:04 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/13 20:46:09 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

//replace tout les symboles correctement ('<' '>' )
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


int is_odd(char *str, char c)
{
	unsigned int i;
	unsigned int cmpt;
	
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
