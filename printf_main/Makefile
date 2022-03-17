# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:28:40 by ldevy             #+#    #+#              #
#    Updated: 2021/12/20 21:45:19 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_str.c  

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJ = ${SRC:.c=.o}

all:	${NAME}

${NAME}:	${OBJ}
	ar -rcs ${NAME} ${OBJ}
	
.c.o:
	${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

clean: 
	rm -f ${OBJ} 

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re 
