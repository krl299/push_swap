/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:03:41 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/14 17:55:25 by cmoran-l         ###   ########.fr       */
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

// Funtions stack
t_stack	*ft_stack_newnode(int value);
void	ft_clearstack(t_stack **stack);
void	ft_stack_addback(t_stack *node, t_stack **stack);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_get_last(t_stack *stack);

#endif
