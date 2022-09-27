/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:11 by averon            #+#    #+#             */
/*   Updated: 2022/09/27 16:16:03 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_core(t_core **mini)
{	
	*mini = malloc(sizeof(t_core));
	if (*mini == NULL)
		exit (EXIT_FAILURE);
}

void	init_struct_var(t_core *mini, char **env)
{
	mini->envp = init_env(env);
	//mini->infile = 0;
	//mini->outfile = 0;
	mini->cmd = NULL;
	mini->nb_pipe = 0;
	mini->tab_tok = NULL;
	mini->bin_dir = NULL;
	mini->fd_input = STDIN_FILENO;
	mini->fd_output = STDOUT_FILENO;
	//mini->exec_params = NULL;
}
