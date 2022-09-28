/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:51:06 by averon            #+#    #+#             */
/*   Updated: 2022/09/28 16:51:39 by jdutschk         ###   ########.fr       */
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
	change_input_output(mini);
	//mini->cmd = ft_split(mini->input, '|');
	//mini->nb_pipe = pipe_calc(mini->cmd);
}

void	change_input_output(t_core *mini)
{
	char **tab;
	int i = 0;
	int j = 0;

	tab = ft_split(mini->input, '<');

	while (tab[i])
	{
		while (tab[i][j] && tab[i][j] != ' ')
			j++;
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
