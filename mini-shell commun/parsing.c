/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/11/10 13:56:57 by averon           ###   ########.fr       */
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

	change_spc(mini->input, '"', '"');
	change_spc(mini->input, 39, 39);
	change_spc2(mini->input, 39, 39);
	working_input = update_input(mini->input, 0, 0);
	replace_all_symbol(working_input);
	tab_of_tokens = ft_split(working_input, ' ');
	free(working_input);
	replace_str_space_tab(tab_of_tokens);
	define_tab_tokens(tab_of_tokens);
	mini->fd_input = change_input_fd(tab_of_tokens);
	mini->fd_output = change_output_fd(tab_of_tokens);
	check_str_token(tab_of_tokens, mini->envp);
	reset_token(tab_of_tokens);
	mini->input = recreate_input(tab_of_tokens);
	mini->cmd = ft_split(mini->input, '|');
	mini->nb_pipe = pipe_calc(mini->cmd);
}

void	reset_token(char **tab)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		j = ft_strlen(tab[i]);
		while (ft_isdigit(tab[i][j]) == 0 && j != 0)
		{
			tab[i][j] = '\0';
			j--;
		}
		tab[i][j] = '\0';
		i++;
	}
}

void	replace_cote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == 39)
			str[i] = ' ';
		i++;
	}
}

void	replace_s_cote(char *str, int indicator)
{
	int	i;

	i = 0;
	while (str[i] && indicator == 0)
	{
		if (str[i] == '"' || str[i] == 39)
			str[i] = ' ';
		else if (str[i] == ' ')
			str[i] = 4;
		i++;
	}
	while (str[i] && indicator == 1)
	{
		if (str[i] == ' ')
			str[i] = 4;
		i++;
	}
}
