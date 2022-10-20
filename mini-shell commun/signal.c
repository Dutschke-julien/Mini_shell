/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:06:17 by averon            #+#    #+#             */
/*   Updated: 2022/10/17 11:55:23 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals(void)
{
	signal(SIGQUIT, sig_handler);
	signal(SIGINT, sig_handler);
}

void	sig_handler(int signal)
{
	if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit\n", 2);
		g_exit_status = 131;
	}
	if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
}

void	signal_hd_loop(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_hd_handler);
}

void	sig_hd_handler(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", 2);
	//free_minishell();
	exit(130);
}

// FAIRE UNE FONCTION POUR VOID LES SIGNAUX DANS LE PROCESSUS ENFANTS ???

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