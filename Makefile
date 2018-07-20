# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edehmlow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 16:46:18 by edehmlow          #+#    #+#              #
#    Updated: 2018/07/18 17:11:33 by edehmlow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

ARCHIVE = ar rc

INDEX = ranlib

OBJ = *.o

HEADER = incl/links.h incl/file_handler.h

SRCS = src/file_handler.c src/links_setup.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	#compile makefile for libft
	$(CC) $(FLAGS) $(SRCS) $(HEADER)
	$(ARCHIVE) $(NAME) $(OBJ)
	$(INDEX) $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
