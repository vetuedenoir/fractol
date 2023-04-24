# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 15:07:13 by kscordel          #+#    #+#              #
#    Updated: 2023/04/10 16:26:21 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

SRC_DIR = src/
OBJ_DIR = obj/
SRC = $(SRC_DIR)fractol.c $(SRC_DIR)utils.c $(SRC_DIR)hook.c $(SRC_DIR)color.c\
	 $(SRC_DIR)formule.c  $(SRC_DIR)ft_atolf.c
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

NAME = fractol

LIBPATH = libft/libft.a
MLXPATH = minilibx-linux/libmlx.a
HEADER = .

all:	$(NAME)

$(NAME):	$(OBJ) | lib
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) ${OBJ} ${MLXPATH} ${LIBPATH} -o ${NAME} -L ./mlx -lX11 -lXext -lm
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

lib:
	@make -C ./libft

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft
		@make clean -C ./minilibx-linux

x:	clean all

re: fclean all

.PHONY: all lib clean fclean re
