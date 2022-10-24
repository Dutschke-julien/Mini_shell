/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:58:36 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/24 18:52:21 by jdutschk         ###   ########.fr       */
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
