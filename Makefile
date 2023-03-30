SRCS =	push_swap.c	parser.c	stacks.c	stack_utils.c	sort.c	operations.c	do_push.c	do_swap.c	do_rotate.c	do_rev_rotate.c	do_move.c cost.c	target.c

OBJS = 		${SRCS:.c=.o}

SRCS_CHECKER = checker.c	parser.c	stacks.c	stack_utils.c	sort.c	operations.c	do_push.c	do_swap.c	do_rotate.c	do_rev_rotate.c	do_move.c cost.c	target.c
OBJS_CHECKER = ${SRCS_CHECKER:.c=.o}

LIBFT = 	libft/libft.a

.c.o:
	${GCC} -c $< -o ${<:.c=.o}

NAME = push_swap

RM = rm -rf

GCC = gcc -Wall -Werror -Wextra

all:		$(LIBFT)	$(NAME)

$(LIBFT):	
		@git submodule update --init
		@make -C libft extra

$(NAME):	${OBJS}
		@${GCC} ${OBJS} ${LIBFT} -o push_swap 

clean:		
		@make -C libft fclean
		@${RM} libft/libft.a push_swap checker *.o

fclean:	clean

re: fclean all

visualizer:	re
	python3 python_visualizer.py `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"`

bonus:	${OBJS_CHECKER}
		@make -C libft extra
		@${GCC} ${OBJS_CHECKER} ${LIBFT} -o checker

.PHONY:	all clean fclean re bonus
