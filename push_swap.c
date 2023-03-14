/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:02:38 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/14 18:01:14 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
	{
		ft_check_arg(argv, &stack_a);
		ft_sort(&stack_a, &stack_b);
		t_stack	*tmp = stack_a;
		while (stack_a)
		{
			printf("%i|", stack_a->value);
			stack_a = stack_a->next;
		}
		printf("\n");
		while (tmp)
		{
			printf("%i|", tmp->index);
			tmp = tmp->next;
		}
		printf("\n");
	}
	return (0);
}
