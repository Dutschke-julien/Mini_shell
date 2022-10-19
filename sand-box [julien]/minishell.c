/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:44:04 by jdutschk          #+#    #+#             */
/*   Updated: 2022/10/19 14:31:54 by jdutschk         ###   ########.fr       */
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
		mini->input = readline("minishell>");
		add_history(mini->input);
		input_split(mini);
		//pipex(mini);
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