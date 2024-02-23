# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 23:15:02 by bmahdi            #+#    #+#              #
#    Updated: 2024/02/23 23:56:38 by bmahdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -lX11 -lXext
SRC = fractol.c events.c math.c untils1.c untils2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all