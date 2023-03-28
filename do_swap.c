/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:31:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/24 12:01:32 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Do swap stack a
void	ft_do_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

// Do swap stack b
void	ft_do_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

// Do swap stack a and b
void	ft_do_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
