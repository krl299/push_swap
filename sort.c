/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:30:45 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/14 18:05:21 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	(void)stack_b;
	size = ft_stack_size(*stack_a);
	ft_assing_index(*stack_a, size);
	printf("%i\n", size);
}

// Bubble sort to assing index each stack node
void	ft_assing_index(t_stack *stack, int size)
{
	t_stack	*node;
	t_stack	*highest;
	int		value;

	while (--size > 0)
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
	}
}
