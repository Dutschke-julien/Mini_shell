/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:11 by averon            #+#    #+#             */
/*   Updated: 2022/11/13 15:15:01 by averon           ###   ########.fr       */
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
	mini->fd_input = 0;
	mini->fd_output = 1;
	mini->cmd = NULL;
	mini->bin_no_path = NULL;
	mini->nb_pipe = 0;
	mini->tab_tok = NULL;
	mini->bin_dir = NULL;
}
