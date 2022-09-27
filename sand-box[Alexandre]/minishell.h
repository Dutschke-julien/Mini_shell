/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:17 by averon            #+#    #+#             */
/*   Updated: 2022/09/13 16:02:18 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h> // mettre strcat dans libft;
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"


typedef struct s_core
{
	char			**envp;
	char			*input;
	char			**cmd;
	char			**tab_tok;
	int				tube[2];
	int				nb_pipe;
	char			*bin_dir;
	char			**path_tab;			
	//char			**exec_params;
}t_core;

// utils

void	ft_free(char **str);
int		ft_error(char *message);
void	check_tab_char(char **tab);

//	minishel + init

void	init_struct_core(t_core **mini);
void	init_struct_var(t_core *mini, char **env);

// lexer + parser

void	input_split(t_core *mini);
int		pipe_calc(char **tab);

// pipex

void	pipex(t_core *mini);
void	ft_child_process(t_core *mini, int i);
void	ft_parent_process(int *tube, int *fd);

// env

int		nbvar_env(char **env);
char	**init_env(char **env);


// exec

void	exec_cmd(t_core *mini, int i);
char	*bin_dir_cat(t_core *mini);
char	*get_path(t_core *mini);


#endif
