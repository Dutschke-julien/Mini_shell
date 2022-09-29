/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:06:17 by averon            #+#    #+#             */
/*   Updated: 2022/09/29 13:58:19 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler_redisp(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 128 + sig_num;
	}
	else if (sig_num == SIGQUIT)
	{	
		write(1, "minishell>  \b\b", 14);
		g_exit_status = 128 + sig_num;
	}
}

void	sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_status = 128 + sig_num;
	}
	else if (sig_num == SIGQUIT)
	{
		g_exit_status = 128 + sig_num;
	}
}
/*

 Cas : interactif

 ctrl C: interruption (SIGINT)
 ctrl D: EOF
 ctrl \: ne fait rien
 
 
 Cas : non interactif

ctrl C: interruption (SIGINT)
ctrl D: EOF
ctrl \: ne fait rien


faire une fonction ctrl c handler

 */