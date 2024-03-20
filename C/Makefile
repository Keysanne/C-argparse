NAME= argparse
COMPILER= gcc 
OBJS=	${FILES:.c=.o}
FILES=	argparse.c \
		main.c		\
		utils.c

all: ${NAME}

${NAME}: ${OBJS}
		${COMPILER} ${OBJS} -o ${NAME} -g

${OBJS}: ${FILES}
		${COMPILER} -c ${FILES} -g

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all