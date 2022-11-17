# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:02:27 by averon            #+#    #+#              #
#    Updated: 2022/11/16 21:01:01 by jdutschk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = 	minishell.c					\
		utils.c						\
		var_env.c					\
		exec_utils.c				\
		exec.c						\
		expanse_dollar.c			\
		heredoc.c					\
		init.c						\
		parsing.c					\
		pipex.c						\
		signal.c					\
		builtins/cd.c				\
		builtins/cd2.c				\
		builtins/echo.c				\
		builtins/env.c				\
		builtins/exit.c				\
		builtins/export.c			\
		builtins/export2.c			\
		builtins/pwd.c				\
		builtins/unset.c			\
		Change_input_fd.c			\
		Change_output_fd.c			\
		check_str_token.c			\
		check_str_token_2.c			\
		define_str_token.c			\
		recreate_input.c			\
		replace_all_symbol.c 		\
		replace_str_tab.c			\
		update_input.c				\
		place_space_in_tab.c 		
		

OBJS = $(SRCS:.c=.o)

HEADERS =	./
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all :		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I $(HEADERS) -I /Users/jdutschk/goinfre/.brew/opt/readline/include -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			$(CC) $(CFLAGS) $(OBJS) libft.a -lreadline -L /Users/jdutschk/goinfre/.brew/opt/readline/lib -o $(NAME) 
 
clean :
			$(RM) $(OBJS)
			$(RM) libft.a

fclean:		clean
			make -C ./libft fclean			
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 
