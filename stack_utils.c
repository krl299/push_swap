/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:32:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/30 13:10:12 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return pointer to the last stack node
t_stack	*ft_get_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

// Return pointer to the second last node
t_stack	*ft_get_secondlast(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

// Case of a error
void	ft_arg_error(t_stack **stack)
{
	ft_clearstack(stack);
	write(2, "Error\n", 6);
	exit(0);
}
