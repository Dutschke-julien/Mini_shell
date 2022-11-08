/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:55:53 by averon            #+#    #+#             */
/*   Updated: 2022/11/08 19:08:16 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_echo(t_core *mini)
{
	if (mini->tab_tok[1] && is_n_option(mini->tab_tok[1]))
		echo_print_option(mini, 2);
	else
	{
		echo_print_option(mini, 1);
		printf("\n");
	}
	g_exit_status = 0;
	return (0);
}

int	is_n_option(char *str)
{
	if (strcmp(str, "-n\0") == 0)
		return (1);
	else
		return (0);
}

void	echo_print_option(t_core *mini, int j)
{
	while (mini->tab_tok[j])
	{
		printf("%s", mini->tab_tok[j]);
		if (mini->tab_tok[j + 1])
			printf(" ");
		j++;
	}
}
