# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:02:27 by averon            #+#    #+#              #
#    Updated: 2022/10/20 12:34:39 by jdutschk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = 	minishell.c	\
		utils.c		\
		env.c		 \
		exec.c	      \
		init.c		   \
		parsing.c	    \
		parsing2.c	     \
		parsing3.c	      \
		parsing4.c	       \
		parsing5.c	        \
		Change_input_fd.c    \
		Change_output_fd.c    \
		recreate_input.c	   \
		change_dollar_in_str.c	\
		pipex.c

OBJS = $(SRCS:.c=.o)

HEADERS =	./
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all :		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			$(CC) $(CFLAGS) $(OBJS) libft.a -lreadline -o $(NAME) 
 
clean :
			$(RM) $(OBJS)
			$(RM) libft.a

fclean:		clean
			make -C ./libft fclean			
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 