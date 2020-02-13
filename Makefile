# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 15:50:27 by hyeokim           #+#    #+#              #
#    Updated: 2020/02/13 03:34:35 by hyeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= BSQ
SRCS	= ft_print.c ft_argv_in.c ft_free.c is_valid_map.c \
		ft_solve.c ft_stdin.c main.c is_valid_sub_func.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
OPTIONS = -I includes
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
			${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} $(OPTIONS) $(FLAGS) $(OBJS) -o $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
