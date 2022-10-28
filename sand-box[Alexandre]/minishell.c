/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/10/28 13:45:02 by averon           ###   ########.fr       */
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
		signals_run(1);
		mini->input = readline("minishell> ");
		add_history(mini->input);
		if (!mini->input)
			exit_exec(mini);
		else if (mini->input)
		{
			input_split(mini);
			pipex(mini);
		}
		free(mini->input);
	}
	return (0);
}
