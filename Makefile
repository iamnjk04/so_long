# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakunwar <nakunwar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 22:29:06 by nakunwar          #+#    #+#              #
#    Updated: 2025/07/08 19:46:07 by nakunwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
CC      = cc
MLX     = minilibx-mac
MLX_LIB = $(MLX)/libmlx.a
CFLAGS  = -Wall -Wextra -Werror -I./$(MLX)
LDFLAGS = -L./$(MLX) -lmlx -framework OpenGL -framework AppKit

SRC     = src/main.c src/map.c src/draw.c src/render.c src/libft_utils.c \
          src/map_check.c src/event.c
OBJ     = $(SRC:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)
	@echo Done...
	@echo Usage:    ./so_long maps/map.ber
	@echo or just:  make test
	@echo Controls: press W A S D to move the Player

src/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: all
	./so_long maps/map.ber