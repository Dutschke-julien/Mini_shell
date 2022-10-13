/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/13 20:42:14 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_calc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i = i - 1;
	return (i);
}

void	input_split(t_core *mini)
{
   char **hello;
   int i = 0;
   char *str;

	str = update_input(mini->input, 0, 0);
	replace_all_symbol(str);
	change_spc(str, '"', '"');
	hello = ft_split(str, ' ');
	printf("%s\n", str);
  while (hello[i])
	{
		printf("hello[%d] = %s\n", i , hello[i]);
		i++;
	}
	//mini->cmd = ft_split(mini->input, '|');
	//mini->nb_pipe = pipe_calc(mini->cmd);
}

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
	replace_symbol2(str, 47);
	change_spc(str, '"', '"');
	if (is_odd(str, '"'))
		return (printf("erreur\n"));
	return (0);
}

void	change_spc(char *str, char first, char second)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] != first && str[i])
			i++;
		i++;
		while (str[i] != second && str[i])
		{
			if (str[i] == ' ')
				str[i] = 'w';
			i++;
		}
		i++;
	}
}
