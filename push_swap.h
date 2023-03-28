/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:03:41 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/24 11:25:48 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack{
	int				value;
	int				index;
	int				place;
	int				target_place;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Funtions to check arguments
void	ft_check_arg(char **argv, t_stack **stack_a);
void	ft_arg_error(t_stack **stack);
int		ft_isnum(char *str);
int		ft_dupes(unsigned int nb);

// Funtions to sort
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_assing_index(t_stack *stack, int size);
int		ft_is_sorted(t_stack *stack);
void	ft_leave_three(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack);
void	ft_set_target_place(t_stack **stack_a, t_stack **stack_b);
int		ft_get_lowest_index_place(t_stack **stack);
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_do_cheap(t_stack **stack_a, t_stack **stack_b);
void	ft_do_move(t_stack **stack_a, t_stack **stack_b, \
		int cost_a, int cost_b);
void	ft_shift_stack(t_stack **stack_a);

// Funtions stack
t_stack	*ft_stack_newnode(int value);
void	ft_clearstack(t_stack **stack);
void	ft_stack_addback(t_stack *node, t_stack **stack);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_get_last(t_stack *stack);
t_stack	*ft_get_secondlast(t_stack *stack);

// Operations available to sort
void	ft_push(t_stack **src, t_stack **dst);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);

// Do operations
void	ft_do_pa(t_stack **stack_b, t_stack **stack_a);
void	ft_do_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_do_sa(t_stack *stack_a);
void	ft_do_sb(t_stack *stack_b);
void	ft_do_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_do_ra(t_stack **stack_a);
void	ft_do_rb(t_stack **stack_b);
void	ft_do_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_do_rra(t_stack **stack_a);
void	ft_do_rrb(t_stack **stack_b);
void	ft_do_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
