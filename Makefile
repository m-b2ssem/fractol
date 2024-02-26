# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 23:15:02 by bmahdi            #+#    #+#              #
#    Updated: 2024/02/25 20:17:34 by bmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
MINILIBX = minilibx-linux/libmlx.a
CFLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lX11 -lXext
SRC = fractol.c events.c math.c untils1.c untils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MINILIBX) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

