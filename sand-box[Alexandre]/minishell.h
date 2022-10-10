/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:17 by averon            #+#    #+#             */
/*   Updated: 2022/10/06 15:19:22 by averon           ###   ########.fr       */
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

typedef struct s_global
{
	pid_t			pid;
	int				exit_status;
}t_global;

t_global			g_g;

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
}t_core;

// utils
void		ft_free(char **str);
int			ft_error(char *message);
void		check_tab_char(char **tab);
int			ft_strcmp(char *s1, char *s2);
int			ft_isnumber(char *str);

//	minishel + init
void		init_struct_core(t_core **mini);
void		init_struct_var(t_core *mini, char **env);

// lexer + parser
void		input_split(t_core *mini);
int			pipe_calc(char **tab);

// pipex
void		pipex(t_core *mini);
void		ft_child_process(t_core *mini, int i);
void		ft_parent_process(int *tube, int *fd);

// var_env
int			nbvar_env(char **env);
char		**init_env(char **env);
char		**realloc_envp(t_core *mini, size_t size);

// exec
void		exec_cmd_all(t_core *mini, int i);
void		exec_cmd_child(t_core *mini, int i);
void		exec_cmd_parents(t_core *mini, int i);
char		*bin_dir_cat(t_core *mini);
char		*get_path(t_core *mini);
void		exit_exec(t_core *mini);
int			exec_builtins_all(t_core *mini);
int			exec_builtins_parent(t_core *mini);
int			exec_builtins_child(t_core *mini);

// free
void		free_minishell(void);

// signal
//static void	process(int sign_num);
void		sig_handler(int sig_num);
void		sig_handler_redisp(int sig_num);
void		process(int sign_num);

//BUILTINS
// Builtin_utils
int			is_forked_command(t_core *mini);

// cd
int			exec_cd(t_core *mini);
void		get_home(char **envp);
char		*save_pwd(char **envp);
void		get_upper_dir(char **envp);
void		update_oldpwd(char **envp, char *temp_pwd);

// echo
int			exec_echo(t_core *mini);

// env
int			exec_env(t_core *mini);

// exit
int			exec_exit(t_core *mini);
int			too_many_args(void);
int			numeric_arg_req(t_core *mini);

// export
int			exec_export(t_core *mini);

// pwd
int			exec_pwd(t_core *mini);
void		read_pwd(char **envp);
void		update_pwd(char **envp);

// unset
int			exec_unset(t_core *mini);
char		**new_envp_unset(t_core *mini, int index);

#endif
