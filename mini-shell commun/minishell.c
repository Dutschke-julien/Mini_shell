/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 19:22:02 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{	
	t_core	*mini;

	(void)argc;
	(void)argv;
	init_struct_core(&mini);
	init_struct_var(mini, env);
	while (42)
	{
		signal(SIGINT, sig_handler_redisp);
		signal(SIGQUIT, sig_handler_redisp);
		mini->input = readline("minishell>");
		add_history(mini->input);
		if (!mini->input)
			exit_exec(mini);
		else if (mini->input)
		{
			signal(SIGINT, sig_handler);
			signal(SIGQUIT, SIG_IGN);
			input_split(mini);
			pipex(mini);
		}
		free(mini->input);
	}
	return (0);
}
// Récupérer en boucle l’entrée de l’utilisateur[ok]
// argv: parametres de la foncion que l'on veut executer[ok]
// le processus quite quand ls est terminé
// processus pere: retour de fork = pid du fils
// processus fils: retour de fork = 0;
// avec un wait, le père attend la fin du processus fils pour se déclencher
// utiliser des fonctions built in: execve // fork // wait
// Path: donne les dossiers qui contiennent des binaires
// separer parsing et execution (commandes, arguments, options ,caracteres
//speciaux)