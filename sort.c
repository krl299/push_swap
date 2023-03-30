/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:26:21 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/30 13:20:27 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Algorithm to sort the stack_a using stack_b as auxiliar
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	ft_assing_index(*stack_a, size);
	if (!ft_is_sorted(*stack_a))
	{
		if (ft_stack_size(*stack_a) == 2)
			ft_do_sa(*stack_a);
		ft_leave_three(stack_a, stack_b);
		ft_sort_three(stack_a);
		while (*stack_b)
		{
			ft_set_target_place(stack_a, stack_b);
			ft_set_cost(stack_a, stack_b);
			ft_do_cheap(stack_a, stack_b);
		}
		if (!ft_is_sorted(*stack_a))
			ft_shift_stack(stack_a);
	}
}

// Bubble sort to assing index each stack node
void	ft_assing_index(t_stack *stack, int size)
{
	t_stack	*node;
	t_stack	*highest;
	int		value;

	while (size > 0)
	{
		node = stack;
		value = INT_MIN;
		highest = NULL;
		while (node)
		{
			if (node->value > value && node->index == 0)
			{
				value = node->value;
				highest = node;
				node = stack;
			}
			else
				node = node->next;
		}
		if (highest != NULL)
			highest->index = size;
		size--;
	}
}

// Check if the stack is sorted
int	ft_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

// Push b leaving 3 in stack a
void	ft_leave_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_do_ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		ft_do_pb(stack_a, stack_b);
		pushed++;
	}
}

// sort stack a with 3 nodes
void	ft_sort_three(t_stack **stack)
{
	int		highest;
	t_stack	*tmp;

	if (ft_is_sorted(*stack))
		return ;
	tmp = *stack;
	highest = tmp->index;
	while (tmp)
	{
		if (tmp->index > highest)
			highest = tmp->index;
		tmp = tmp->next;
	}
	if ((*stack)->index == highest)
		ft_do_sa(*stack);
	if ((*stack)->next->index == highest)
		ft_do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_do_sa(*stack);
}
