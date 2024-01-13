# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kscordel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 17:47:39 by kscordel          #+#    #+#              #
#    Updated: 2022/12/27 18:20:35 by kscordel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ft_printf \
	puts \
	

OBJ = $(addsuffix .o, ${SRC})
CC = cc 
HEADER = .
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft/
	
all: $(NAME)

%.o:%.c
	$(CC) -c $(FLAGS) $< -o $@ -I${HEADER}

$(NAME): ${LIBFT_DIR}libft.a ${OBJ}
		cp ${LIBFT_DIR}libft.a ./${NAME}
		ar rcs ${NAME} ${OBJ}
				
${LIBFT_DIR}libft.a:
		make all -C ${LIBFT_DIR}
		
clean:
		rm -f ${OBJ}
		make clean -C ${LIBFT_DIR}		
fclean: clean
		rm -f $(NAME)
		make fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
