/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:03:41 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/13 12:48:29 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack{
	int		value;
	int		cost;
	s_stack	*next;
}	t_stack;

void	ft_check_arg(char **argv, t_stack **stack_a);
void	ft_arg_error(t_stack **stack);
int		ft_isnum(char *str);
int		ft_dupes(unsigned int nb);

void	ft_sort(t_stack **stack_a, t_stack **stack_b);

#endif
