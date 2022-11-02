/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/11/02 15:09:06 by averon           ###   ########.fr       */
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
		signals_run(1);
		mini->input = readline("minishell> ");
		add_history(mini->input);
		if (!mini->input || mini->input[0] == '\04')
			exit_mini(mini);
		if (mini->input)
			launch_exec(mini, i);
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

void	free_minishell(t_core *mini)
{
	if (mini->envp)
		ft_free(mini->envp);
	if (mini->cmd)
		ft_free(mini->cmd);
	if (mini->tab_tok)
		ft_free(mini->tab_tok);
	if (mini->path_tab)
		ft_free(mini->path_tab);
	if (mini)
		free(mini);
	rl_clear_history();
}
