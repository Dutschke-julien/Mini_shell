/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:06:17 by averon            #+#    #+#             */
/*   Updated: 2022/10/28 13:46:11 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_run(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, back_slash);
	}
}

void	restore_prompt(int sig)
{
	g_exit_status = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

void	ctrl_c(int sig)
{
	g_exit_status = 130;
	write(1, "\n", 1);
	(void)sig;
}

void	back_slash(int sig)
{
	g_exit_status = 131;
	printf("Quit: 3\n");
	(void)sig;
}


/*

NON INTERACTIF : idem bash

ctrl C: (SIGINT)
	- en cours de frappe: passe à la ligne et nouveau prompt (on garde ^C dans minishell) ---> OK
	- sur ligne vide: idem ---> OK

ctrl D: (EOT)
	- en cours de frappe: ne fait rien ---> OK	
	- sur ligne vide: écrit "exit" et quitte bash ---> OK

ctrl \: (SIGQUIT)
	- en cours de frappe: ne fait rien ---> OK
	- sur ligne vide: ne fait rien ---> OK


INTERACTIF:

ctrl C: interruption (SIGINT)
	- ecrit ^C, passe a la ligne et donne le prompt ---> OK

ctrl D: EOF
	- donne le prompt ---> OK

ctrl \: 
	- ecrit "^\Quit: 3" et passe à la ligne et donne le prompt" --> OK

 */
