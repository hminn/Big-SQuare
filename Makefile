# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjeon <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 22:51:29 by sjeon             #+#    #+#              #
#    Updated: 2020/02/13 01:57:14 by sjeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = BSQ
OBJ = main.o is_valid_map.o is_valid_func.o ft_solve.o ft_print.o ft_free.o

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -o ^@ 

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm *.o $(NAME)
