# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 16:02:27 by averon            #+#    #+#              #
#    Updated: 2022/09/29 14:08:18 by averon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = 	minishell.c	\
		utils.c		\
		env.c		\
		exec.c		\
		init.c		\
		parsing.c	\
		pipex.c		\
		signal.c	

OBJS = $(SRCS:.c=.o)

HEADERS =	./
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all :		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I $(HEADERS) -I$(HOME)/.brew/opt/readline/include -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			$(CC) $(CFLAGS) $(OBJS) libft.a -lreadline -L/$(HOME)/.brew/opt/readline/lib -o $(NAME) 
 
clean :
			$(RM) $(OBJS)
			$(RM) libft.a

fclean:		clean
			make -C ./libft fclean			
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 
