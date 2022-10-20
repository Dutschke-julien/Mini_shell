/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/10/20 14:17:30 by jdutschk         ###   ########.fr       */
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
	char	**hello;
	char	*str;

	str = update_input(mini->input, 0, 0);
	replace_all_symbol(str);
	change_spc(str, '"', '"');
	change_spc(str, 39, 39);
	hello = ft_split(str, ' ');
	replace_str_space_tab(hello);
	define_tab_tokens(hello);
	mini->fd_input = change_input_fd(hello);
	mini->fd_output = change_output_fd(hello);
	check_str_token(hello);
	reset_token(hello);
	mini->input = recreate_input(hello);
	mini->cmd = ft_split(mini->input, '|');
	mini->nb_pipe = pipe_calc(mini->cmd);
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

void	reset_token(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		tab[i][ft_strlen(tab[i]) - 1] = '\0';
		i++;
	}
}
