/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:17 by averon            #+#    #+#             */
/*   Updated: 2022/09/27 13:42:48 by jdutschk         ###   ########.fr       */
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
	int				fd_input;
	int				fd_output;			
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
void	change_input_output(t_core *mini);

// env

int		nbvar_env(char **env);
char	**init_env(char **env);

// exec

void	exec_cmd(t_core *mini, int i);
char	*bin_dir_cat(t_core *mini);
char	*get_path(t_core *mini);

#endif
