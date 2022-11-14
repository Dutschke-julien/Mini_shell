/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:44:17 by averon            #+#    #+#             */
/*   Updated: 2022/11/13 16:04:39 by averon           ###   ########.fr       */
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
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
token 0 = chaine simple
token 1 = <		"dir_in"
token 2 = > 	"dir_out"
token 3 = << 	"heredoc"
token 4 = >> 	"append"
token 5 = $ 	"dollar"
token 6 = " 	"double_quote"
token 7 = ' 	"single_quote"
token 8 = |  	"pipe"
*/

int				g_exit_status;

typedef struct s_core
{
	pid_t		pid;
	char		**envp;
	char		*input;
	char		**cmd;
	char		**tab_tok;
	char		*bin_no_path;
	int			tube[2];
	int			nb_pipe;
	char		*bin_dir;
	char		**path_tab;
	int			fd_input;
	int			fd_output;			
}t_core;

//place_space_in_tab.c
void		place_space_in_tab(char **tab);

//[parsing]
void		reset_token(char **tab);
void		define_tab_tokens(char **tab);
void		replace_cote(char *str);
void		replace_s_cote(char *str, int indicator);

//recreate_input
int			all_strlen(char **tab);
char		*recreate_input(char **tab);
char		*ft_strjoin_free(char const *s1, char const *s2);

//check_str_token[1..2]
void		check_str_token(char **tab, char **env);
char		*change_dollar_in_str(char *str, char **env, int cmpt_space);
char		*transform_str_dollar2(char **tab, int *space_data);
char		*add_space_str_dollar(char *str, int space);
char		*transforming_into_six(char *str);
char		*transform_str_dollar(char **tab, int *space_data, char **env);
char		*replace_str_by_env(char *str, char **env);

//update_input
char		*update_input(char *str, int i, int j);
void		change_spc(char *str, char first, char second);
void		change_spc2(char *str, char first, char second);

//define_str_token
char		*define_str_token(char *str);
char		*define_str_token2(char *str);
char		*define_str_token3(char *str);
char		*define_str_token4(char *str);
void		change_pipe_in_str(char *str);

//change input+output
int			change_input_fd(char **tab);
char		*cmd_with_space(char *str, int i, int j);
int			cmpt_this(char *str, char c);
int			get_tokens(char *str);
int			is_dir_in(char *str);
int			is_heredoc(char *str);
void		delete_case(char **tab, int local_case);
int			change_output_fd(char **tab);
int			is_dir_out(char *str);
int			is_append(char *str);

//replace_str_tab
void		replace_str_space_tab(char **tab);
void		replace_str_space(char *str);
void		define_tab_tokens(char **tab);
char		*define_str_token(char *str);

//replace_all_symbol
int			replace_all_symbol(char *str);
void		replace_symbol(char *str, char symbol);
void		replace_symbol2(char *str, char c);
int			is_odd(char *str, char c);

// utils
int			ft_error(char *message);
void		check_tab_char(char **tab);
int			ft_strcmp(char *s1, char *s2);
int			ft_isnumber(char *str);
int			is_occurence(char c);

//	minishel + init
void		exit_mini(t_core *mini);
void		free_minishell(t_core *mini);
void		init_struct_core(t_core **mini);
void		init_struct_var(t_core *mini, char **env);

// lexer + parser
void		input_split(t_core *mini);
int			pipe_calc(char **tab);

//	expanse_dollar
int			expanse_dollar(char **envp, char *str);
char		*dollar_is_in_env(char **envp, char *str);

// heredoc

int			heredoc(char *name);
int			heredoc_loop(char *limiter, int fd);

// pipex
void		pipex(t_core *mini);
void		ft_child_process(t_core *mini, int i);
void		ft_parent_process(int *tube, int *fd, pid_t pid);
void		status_child(void);

// var_env
int			nbvar_env(char **env);
char		**init_env(char **env);
int			is_in_env(char **envp, char *str);
void		print_env(char **envp, char *envp_name);

// exec_utils
char		*bin_dir_cat(t_core *mini);
char		*get_var_path(t_core *mini);
char		*get_path(t_core *mini);
//int			check_path(char *str);

// exec
void		launch_exec(t_core *mini, int i);
void		exec_cmd_pipex(t_core *mini, int i);
void		execve_message(t_core *mini);
int			exec_builtins_no_fork(t_core *mini);
int			exec_builtins_fork(t_core *mini);

// signal
void		signals_run(int sig);
void		restore_prompt(int sig);
void		ctrl_c(int sig);
void		back_slash(int sig);

//BUILTINS
// cd1
int			exec_cd(t_core *mini);
int			exec_cd2(t_core *mini, char *temp_pwd);
void		get_home(char **envp);

// cd2
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
int			exec_pwd(void);
void		update_pwd(char **envp);

// unset
int			exec_unset(t_core *mini);
char		**new_envp_unset(t_core *mini, int index);

#endif
