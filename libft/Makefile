SRCS		=	ft_strncmp.c ft_bzero.c ft_calloc.c ft_strlen.c ft_strdup.c ft_split.c \
				ft_substr.c ft_strjoin.c ft_putstr.c
OBJS		=	${SRCS:.c=.o}
INCS		=	includes
NAME		=	libft.a
GCC			=	gcc
ARRC		=	ar rc
RLIB		=	ranlib
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
.c.o:
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

all:			${NAME}

${NAME}:		${OBJS}
				${ARRC} ${NAME} ${OBJS}
				${RLIB} ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
