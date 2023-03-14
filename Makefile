SRCS =	push_swap.c	parser.c	stacks.c	sort.c

OBJS = 		${SRCS:.c=.o}

SRCS_CHECKER = ./checker/*.c

OBJS_CHECKER =${SRCS_CHECKER:.c=.o}

LIBFT = 	libft/libft.a

.c.o:
	${GCC} -c $< -o ${<:.c=.o}

NAME = push_swap

RM = rm -rf

GCC = gcc -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	${OBJS}
		@make -C libft extra
		@${GCC} ${OBJS} ${LIBFT} -o push_swap

clean:		
		@make -C libft fclean
		@${RM} libft/libft.a push_swap checker *.o

fclean:	clean

re: fclean all

bonus:
		${GCC} ${OBJS_CHECKER} ${LIBFT} -o checker

.PHONY:	all clean fclean re bonus
