/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:11 by averon            #+#    #+#             */
/*   Updated: 2022/10/19 14:57:53 by jdutschk         ###   ########.fr       */
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
	mini->cmd = NULL;
	mini->nb_pipe = 0;
	mini->tab_tok = NULL;
	mini->bin_dir = NULL;
	mini->fd_input = STDIN_FILENO;
	mini->fd_output = STDOUT_FILENO;
}
