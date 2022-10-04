/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:11 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 19:19:00 by averon           ###   ########.fr       */
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
}
