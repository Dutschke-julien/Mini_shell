/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:13:45 by averon            #+#    #+#             */
/*   Updated: 2022/10/19 12:23:39 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// for ctrl-C 

/*static void	handler(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 130;
}*/

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




/*int	heredoc(char *name)
{
	int		fd;
	
	fd = open("test.txt", O_CREAT | O_TRUNC | O_WRONLY);	
	heredoc_loop(ft_strdup(name), fd);
	
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	close(fd[1]);

	return (fd);
}

void	heredoc_loop(char *limiter, int fd)
{
	char	*line;
	int		size;

	signal_hd_loop();
	
	size = ft_strlen(limiter);

	while (1)
	{
		line = readline("> ");
		if (!line || (!ft_strncmp(limiter, line, size) && !line[size]))
		{	
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
	free(limiter);
	exit(0);
}*/