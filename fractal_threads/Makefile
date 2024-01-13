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
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src/
OBJ_DIR = obj/
SRC = $(SRC_DIR)fractol.c $(SRC_DIR)utils.c $(SRC_DIR)hook.c $(SRC_DIR)color.c\
	 $(SRC_DIR)formule.c $(SRC_DIR)close.c $(SRC_DIR)init1.c  $(SRC_DIR)init2.c\
	 $(SRC_DIR)redefinition.c $(SRC_DIR)original_color.c $(SRC_DIR)original_color2.c
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

NAME = fractol

LIBPATH = libft/libft.a
MLXPATH = minilibx-linux/libmlx.a

all:	$(NAME)

$(NAME):	$(OBJ) | $(LIBPATH) $(MLXPATH)
	$(CC) $(CFLAGS) ${OBJ} ${MLXPATH} ${LIBPATH} -o ${NAME} -L ./mlx -lX11 -lXext -lm -lpthread
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c fractol.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBPATH):
	@make -j -C ./libft

$(MLXPATH):
	@make -j -C ./minilibx-linux

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft
		@make clean -C ./minilibx-linux

re: fclean all

.PHONY: all lib clean fclean re
