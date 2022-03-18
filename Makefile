# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 17:24:43 by ldevy             #+#    #+#              #
#    Updated: 2022/03/18 12:21:57 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/main.c, srcs/first/first.c

OBJS	= ${SRCS:.c=.o}

NAME 	= fractol

RM		= rm -f

CC		= cc

LIBS	= /libft_main/libft.a, /printf_main/libftprintf.a

CFLAGS	= -Wall -Wextra -Werror -g3

all:		${NAME}

.c.o:
			${CC} -I/usr/include -Imlx -c $< -o ${<:.c=.o}

# pour mac
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

#pour mac
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re