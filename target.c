/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:18:40 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/24 11:30:41 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Assigns a place to each node of a stack from top to bottom
static void	ft_set_place(t_stack **stack)
{
	t_stack	*tmp;
	int		place;

	tmp = *stack;
	place = 0;
	while (tmp)
	{
		tmp->place = place;
		tmp = tmp->next;
		place++;
	}
}

// Assign the best target place in stack a
// for the given index of a node in stack b.
static int	ft_set_target(t_stack **stack_a, int index_b, \
		int target_index, int target_place)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_place = tmp->place;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_place);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_place = tmp->place;
		}
		tmp = tmp->next;
	}
	return (target_place);
}

// Assigns a target place in stack a to each node of stack a.
void	ft_set_target_place(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target_place;

	tmp = *stack_b;
	ft_set_place(stack_a);
	ft_set_place(stack_b);
	target_place = 0;
	while (tmp)
	{
		target_place = ft_set_target(stack_a, tmp->index, \
		INT_MAX, target_place);
		tmp->target_place = target_place;
		tmp = tmp->next;
	}
}

// Get the current place of the node with the lowest index within a stack.
int	ft_get_lowest_index_place(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_place;

	tmp = *stack;
	lowest_index = INT_MAX;
	ft_set_place(stack);
	lowest_place = tmp->place;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_place = tmp->place;
		}
		tmp = tmp->next;
	}
	return (lowest_place);
}
