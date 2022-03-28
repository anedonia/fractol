# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 17:24:43 by ldevy             #+#    #+#              #
#    Updated: 2022/03/28 17:31:59 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = $(addprefix srcs/, main.c first.c fractals/burningship.c fractals/julia.c fractals/mandelbrot.c hooks/hooks.c tools/colors.c tools/tool.c)

OBJS	= ${SRC:.c=.o}

NAME 	= fractol

RM		= rm -f

CC		= cc

LIBS 	= ft_printf/ft_printf.a

CFLAGS	= -Wall -Wextra -Werror -g3

bonus: all

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I/usr/include -I ft_printf -I libft -Imlx -c $< -o ${<:.c=.o}

# pour mac
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

${NAME}:	${OBJS}
			make -C mlx
			make -C ft_printf
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}

#pour mac
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			make -C mlx clean
			make -C ft_printf clean
			${RM} ${OBJS}

fclean:		clean
			make -C ft_printf fclean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus