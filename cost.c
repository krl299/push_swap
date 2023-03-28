/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:04:34 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/24 11:20:57 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Set costs of each node
void	ft_set_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_stack_size(tmp_a);
	size_b = ft_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->place;
		if (tmp_b->place > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->place) * -1;
		tmp_b->cost_a = tmp_b->target_place;
		if (tmp_b->target_place > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_place) * -1;
		tmp_b = tmp_b->next;
	}
}

// Return absolute of a given number
static int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

// Do operations for the cheapest node
void	ft_do_cheap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheap;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheap = INT_MAX;
	while (tmp)
	{
		if ((ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b)) < ft_abs(cheap))
		{
			cheap = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_do_move(stack_a, stack_b, cost_a, cost_b);
}
