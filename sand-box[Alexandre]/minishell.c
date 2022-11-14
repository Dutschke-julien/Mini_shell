/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/11/13 18:33:30 by averon           ###   ########.fr       */
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
		{	
			g_exit_status = 0;
			exit_mini(mini);
		}
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
	exit(g_exit_status);
}

void	free_minishell(t_core *mini)
{
	if (mini->envp)
		ft_free(mini->envp);
	if (mini->cmd)
		ft_free(mini->cmd);
	/*if (mini->tab_tok)
		ft_free(mini->tab_tok);*/
	/*if (mini->path_tab)
		ft_free(mini->path_tab);*/
	if (mini)
		free(mini);
	rl_clear_history();
}

void	change_spc2(char *str, char first, char second)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] != first && str[i])
			i++;
		if (str[i])
			i++;
		while (str[i] != second && str[i])
		{
			if (str[i] == '$')
				str[i] = 8;
			i++;
		}
		if (str[i])
			i++;
	}
}
