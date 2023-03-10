/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:03:41 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/10 11:33:24 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack{
	struct s_stack	*next;
	int				cost;
	int				index;
	int				value;
	int				head;
}	t_stack;

int		ft_check_arg(char **argv, t_stack **stack_a);

void	ft_sort(t_stack **stack_a, t_stack **stack_b);

#endif
