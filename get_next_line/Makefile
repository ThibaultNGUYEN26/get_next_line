# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 16:16:13 by thibnguy          #+#    #+#              #
#    Updated: 2022/12/12 16:33:16 by thibnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I ./includes
OBJS = ${SRCS:.c=.o}

SRCS = get_next_line.c

${NAME} : ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all : ${NAME}

.c.o:
	${CC} ${CFLAGS} ${HEADER} -c $< -o ${<:.c=.o}

clean :
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re