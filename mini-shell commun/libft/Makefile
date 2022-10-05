# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 09:52:49 by alexandreve       #+#    #+#              #
#    Updated: 2022/04/29 11:58:00 by averon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	ft_atoi.c 		ft_bzero.c		ft_calloc.c						\
		ft_isalnum.c 	ft_isalpha.c 	ft_isascii.c 	ft_isdigit.c	\
		ft_isprint.c 													\
		ft_itoa.c 														\
		ft_memchr.c 	ft_memcmp.c 	ft_memcpy.c 	ft_memmove.c 	\
		ft_memset.c  													\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c 	\
		ft_split.c  													\
		ft_strchr.c 	ft_strdup.c 	ft_striteri.c 	ft_strjoin.c 	\
		ft_strlcat.c 	ft_strlcpy.c  	ft_strlen.c 	ft_strmapi.c 	\
		ft_strncmp.c  	ft_strnstr.c 	ft_strrchr.c 	ft_strtrim.c 	\
		ft_substr.c 													\
		ft_tolower.c 	ft_toupper.c									\
		get_next_line.c													\
		ft_printf.c														\
		ft_printf_hexa.c				ft_printf_ptr.c					\
		ft_printf_unsint.c				ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

HEADERS = ./

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
			$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

bonus:		$(NAME)
			ar rc $(NAME)

all :		$(NAME)
 
clean :
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 