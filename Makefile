# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edehmlow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 16:46:18 by edehmlow          #+#    #+#              #
#    Updated: 2018/07/23 14:49:37 by edehmlow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
FLAGS = -Wall -Wextra -Werror -o

LIBDIR = libft/
LIB = $(LIBDIR)libft.a

SRC = file_handler.c main.c fillit.c fillit_utilities.c tet_setup.c \
	  check_valid_file.c basic_checks.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBDIR)
	$(CC) $(SRC) $(FLAGS) $(NAME) $(LIB)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all
