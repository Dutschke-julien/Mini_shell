/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:17 by averon            #+#    #+#             */
/*   Updated: 2022/10/03 19:22:01 by averon           ###   ########.fr       */
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

int		g_exit_status;

typedef struct s_core
{
	pid_t			pid;
	char			**envp;
	char			*input;
	char			**cmd;
	char			**tab_tok;
	int				tube[2];
	int				nb_pipe;
	char			*bin_dir;
	char			**path_tab;			
}t_core;

// utils

void	ft_free(char **str);
int		ft_error(char *message);
void	check_tab_char(char **tab);
int		ft_strcmp(char *s1, char *s2);

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

// var_env

int		nbvar_env(char **env);
char	**init_env(char **env);
char	**realloc_envp(t_core *mini, size_t size);

// exec

void	exec_cmd(t_core *mini, int i);
char	*bin_dir_cat(t_core *mini);
char	*get_path(t_core *mini);
void	exit_exec(t_core *mini);
int		exec_builtins(t_core *mini);

// signal
//static void	process(int sign_num);

void	sig_handler(int sig_num);
void	sig_handler_redisp(int sig_num);

// cd

int		exec_cd(t_core *mini);
void	get_home(char **envp);
char	*save_pwd(char **envp);
void	get_upper_dir(char **envp);
void	update_oldpwd(char **envp, char *temp_pwd);

// echo

int		exec_echo(t_core *mini);

// env

int		exec_env(t_core *mini);

// exit

int		exec_exit(t_core *mini);

// export

int		exec_export(t_core *mini);

// pwd

int		exec_pwd(t_core *mini);
void	read_pwd(char **envp);
void	update_pwd(char **envp);

// unset

int		exec_unset(t_core *mini);
char	**new_envp_unset(t_core *mini, int index);

#endif
