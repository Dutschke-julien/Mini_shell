/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/11/07 13:50:26 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{	
	t_core	*mini;
	int		i;

	i = 0;
	(void)argc;
	(void)argv;
	init_struct_core(&mini);
	init_struct_var(mini, env);
	while (42)
	{
		signals();
		mini->input = readline("minishell>");
		add_history(mini->input);
		if (!mini->input)
			exit_exec(mini);
		else if (mini->input)
		{
			input_split(mini);
			if (mini->nb_pipe == 0)
			{	
				mini->tab_tok = ft_split(mini->cmd[i], ' ');
				if (ft_strncmp(mini->tab_tok[0], "<<", 2) == 0)
					heredoc(&mini->tab_tok[0][2], mini);
				else if (is_builtin(mini) == 1)
					exec_builtins_all(mini);
				else if (is_builtin(mini) == 0)
					execve_cmd_exec(mini);
				ft_free(mini->tab_tok);
			}
			else
				pipex(mini);
			
		}
		free(mini->input);
	}
	return (0);
}
