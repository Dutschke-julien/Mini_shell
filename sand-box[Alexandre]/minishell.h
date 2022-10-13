/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:17 by averon            #+#    #+#             */
/*   Updated: 2022/10/12 18:12:39 by averon           ###   ########.fr       */
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

int				g_exit_status;

typedef struct s_core
{
	pid_t		pid;
	char		**envp;
	char		*input;
	char		**cmd;
	char		**tab_tok;
	int			tube[2];
	int			nb_pipe;
	char		*bin_dir;
	char		**path_tab;			
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

//	expanse_dollar
int			expanse_dollar(char **envp, char *str);
char		*dollar_is_in_env(char **envp, char *str);

// pipex
void		pipex(t_core *mini);
void		ft_child_process(t_core *mini, int i);
void		ft_parent_process(int *tube, int *fd);

// var_env
int			nbvar_env(char **env);
char		**init_env(char **env);
int			is_in_env(char **envp, char *str);
void		print_env(char **envp, char *envp_name);

// exec_utils
char		*bin_dir_cat(t_core *mini);
char		*get_path(t_core *mini);
//void		forked_cmd_exec(t_core *mini);
void		exit_exec(t_core *mini);

// exec
void		execve_cmd_exec(t_core *mini);
void		exec_cmd_pipex(t_core *mini, int i);
//void		exec_cmd_child(t_core *mini);
//void		exec_cmd_parents(t_core *mini);
int			exec_builtins_all(t_core *mini);
//int		exec_builtins_parent(t_core *mini);
//int		exec_builtins_child(t_core *mini);

// free
void		free_minishell(void);

// signal
void		handler(int signal);

//BUILTINS
// Builtin_utils
int			is_builtin(t_core *mini);
int			is_forked_command(t_core *mini);

// cd
int			exec_cd(t_core *mini);
void		get_home(char **envp);
char		*save_pwd(char **envp);
void		get_upper_dir(char **envp);
void		update_oldpwd(char **envp, char *temp_pwd);

// echo
int			exec_echo(t_core *mini);
int			is_n_option(char *str);
void		echo_print_option(t_core *mini, int j);

// env
int			exec_env(t_core *mini);
char		**realloc_envp_unset(t_core *mini, size_t size);

// exit
int			exec_exit(t_core *mini);
int			too_many_args(void);
void		numeric_arg_req(t_core *mini);

// export
int			exec_export(t_core *mini);
void		export_print(char **envp);
char		**export_add_variable(t_core *mini, char *str);
void		export_change_value(char **envp, char *str);
char		**new_envp_export(t_core *mini, size_t size);

// export2
int			is_valid_var_name(char *str);
void		export_error(char *str);
void		env_sort(char **envp);

// pwd
int			exec_pwd(t_core *mini);
void		print_pwd(void);
void		update_pwd(char **envp);

// unset
int			exec_unset(t_core *mini);
char		**new_envp_unset(t_core *mini, int index);

#endif
