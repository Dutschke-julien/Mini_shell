/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/19 18:03:59 by jdutschk         ###   ########.fr       */
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

	i = 0;
	str = update_input(mini->input, 0, 0);
	replace_all_symbol(str);
	change_spc(str, '"', '"');
	change_spc(str, 39, 39);
	hello = ft_split(str, ' ');
	replace_str_space_tab(hello);
	define_tab_tokens(hello);
	change_input_fd(hello);
	change_output_fd(hello);
	while (hello[i])
	{
		printf("hello[%d] = %s\n", i, hello[i]);
		i++;
	}
	str = recreate_input(hello);
	printf("voici l'input reformer   %s\n", str);
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
	replace_symbol2(str, 39);
	if (is_odd(str, '"'))
		return (printf("erreur\n"));
	if (is_odd(str, 39))
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
				str[i] = 4;
			i++;
		}
		i++;
	}
}
