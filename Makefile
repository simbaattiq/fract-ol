# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 18:29:00 by mel-atti          #+#    #+#              #
#    Updated: 2024/06/20 18:29:21 by mel-atti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = /nfs/homes/mel-atti/Desktop/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
INCLUDES = -I$(MLX_DIR)
LIBS = -L$(MLX_DIR) -Imlx_linux -lXext -lX11 -lm -lz
SRCS = main.c fractol.c fractol_events.c free_errors.c math_functions.c \
    rendering_fractol.c string_lib.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx_linux -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
