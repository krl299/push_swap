/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:02:38 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/31 14:41:18 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_leaks(void)
{
	system("leaks -q push_swap");
}

// Start the program push_swap
int	main(int argc, char *argv[])
{
	atexit(ft_leaks);
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
	}
	ft_clearstack(&stack_a);
	return (0);
}


