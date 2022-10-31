/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/10/31 11:46:11 by averon           ###   ########.fr       */
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
		if (!mini->input || mini->input[0] == '\04')
			exit_mini(mini);
		else if (mini->input)
		{
			input_split(mini);
			pipex(mini);
		}
		free(mini->input);
	}
	return (0);
}

void	exit_mini(t_core *mini)
{
	ft_putendl_fd("exit", 1);
	free_minishell(mini);
	exit(0);
}
