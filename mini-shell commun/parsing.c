/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/11/04 17:36:40 by averon           ###   ########.fr       */
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
	char	**tab_of_tokens;
	char	*working_input;

	working_input = update_input(mini->input, 0, 0);
	replace_all_symbol(working_input);
	change_spc(working_input, '"', '"');
	change_spc(working_input, 39, 39);
	tab_of_tokens = ft_split(working_input, ' ');
	replace_str_space_tab(tab_of_tokens);
	define_tab_tokens(tab_of_tokens);
	mini->fd_input = change_input_fd(tab_of_tokens);
	mini->fd_output = change_output_fd(tab_of_tokens);
	check_str_token(tab_of_tokens, 0);
	reset_token(tab_of_tokens);
	mini->input = recreate_input(tab_of_tokens);
	mini->cmd = ft_split(mini->input, '|');
	mini->nb_pipe = pipe_calc(mini->cmd);
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

void	replace_cote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' )
			str[i] = ' ';
		i++;
	}	
}
