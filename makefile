# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anespoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/21 13:34:31 by anespoul          #+#    #+#              #
#    Updated: 2016/04/22 16:03:31 by anespoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol

FLAGS = -Imlx -Wall -Wextra -Werror -O3

SRC = ./libft/libft.a carpet.c circle.c color.c draw_menger.c fractal.c \
		ft_error.c init.c init_sierp.c julia.c key_hook.c main.c \
		mandelbrot.c menger.c mouse_hook.c sierp.c sierp_event.c \
		handle_pos.c

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	make -C libft clean

fclean: clean
	make -C libft clean
	rm -fv $(NAME)

re: fclean all
