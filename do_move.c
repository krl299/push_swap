/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:45:44 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/24 12:29:35 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Do moves stack a depends on cost value
static void	ft_do_rotate_a(t_stack **stack_a, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			ft_do_ra(stack_a);
			cost--;
		}
		else if (cost < 0)
		{
			ft_do_rra(stack_a);
			cost++;
		}
	}
}

// Do moves stack b depends on cost value
static void	ft_do_rotate_b(t_stack **stack_b, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			ft_do_rb(stack_b);
			cost--;
		}
		else if (cost < 0)
		{
			ft_do_rrb(stack_b);
			cost++;
		}
	}
}

// Do move to sort stack
void	ft_do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			ft_do_rrr(stack_a, stack_b);
			cost_a++;
			cost_b++;
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			ft_do_rr(stack_a, stack_b);
			cost_a--;
			cost_b--;
		}
	}
	if (cost_a != 0)
		ft_do_rotate_a(stack_a, cost_a);
	if (cost_b != 0)
		ft_do_rotate_b(stack_b, cost_b);
	ft_do_pa(stack_b, stack_a);
}

// Shift stack to sort the indexes on stack a
void	ft_shift_stack(t_stack **stack_a)
{
	int	lowest_place;
	int	size;

	size = ft_stack_size(*stack_a);
	lowest_place = ft_get_lowest_index_place(stack_a);
	if (lowest_place > size / 2)
	{
		while (lowest_place < size)
		{
			ft_do_rra(stack_a);
			lowest_place++;
		}
	}
	else
	{
		while (lowest_place > 0)
		{
			ft_do_ra(stack_a);
			lowest_place--;
		}
	}
}
