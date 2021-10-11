SRCS 		= 	pipex.c path.c libft/libft.a
NAME		= 	pipex
INCS		=	libft -I ./
GCC			=	gcc
CHECKER		=	checker
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all:			${NAME}

${NAME}:
	@make -C ./libft
	${GCC} ${CFLAGS} ${SRCS} -I${INCS} -o ${NAME}




clean:
				${RM} ${NAME}
				@make clean -C ./libft

fclean:			clean
				${RM} ${NAME}
				@make fclean -C ./libft

re:				fclean all
.PHONY:
				all, fclean, clean, re