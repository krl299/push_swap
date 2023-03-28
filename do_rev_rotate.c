/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:32:06 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/21 11:52:06 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Do reverse rotate stack a
void	ft_do_rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_printf("rra\n");
}

// Do reverse rotate stack b
void	ft_do_rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_printf("rrb\n");
}

// Do reverse rotate stack a and b
void	ft_do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
