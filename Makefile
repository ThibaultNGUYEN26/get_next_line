NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I ./includes
OBJS = ${SRCS:.c=.o}

SRCS = get_next_line.c get_next_line_utils.c

${NAME} : ${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus:	$(OBJS)
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