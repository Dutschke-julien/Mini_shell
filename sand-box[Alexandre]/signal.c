/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:06:17 by averon            #+#    #+#             */
/*   Updated: 2022/10/06 15:19:24 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	sig_handler_redisp(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_g->exit_status = 128 + sig_num;
	}
	else if (sig_num == SIGQUIT)
	{	
		rl_on_new_line();
		rl_redisplay();
		g_g->exit_status = 128 + sig_num;
	}
}*/

/*void	sig_handler(int sig_num)
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
}*/

void	sig_handler(int sign_num)
{
	if ((sign_num == SIGINT || sign_num == SIGQUIT) && g_g.pid != 0)
		process(sign_num);
	else
	{
		if (sign_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_g.exit_status = 1;
			//prompt();
		}
		else if (sign_num == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}

void	process(int sign_num)
{
	if (!kill(g_g.pid, sign_num))
	{
		if (sign_num == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_g.exit_status = 131;
		}
		else if (sign_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_g.exit_status = 130;
		}
	}
	else if (sign_num == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_g.exit_status = 1;
		//prompt();
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