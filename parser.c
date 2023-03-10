/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/10 17:46:15 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isnum(char *str)
{
	int i;

	i = -1;
	if (str[0] == '-' || str[0] == '+' && str[1])
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		ft_duplicates(unsigned int nb)
{
	static int	map[4294967296];

	
}

void	ft_error(t_stack **stack)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_check_arg(char **arg, t_stack **stack_a)
{
	int		i;
	char	*str;

	i = 0;
	while (arg[++i])
	{
		str = ft_split(arg[i]);
		if (!*str)
			ft_error(stack_a);
		while (*str)
		{
			if (!ft_isnum(*str) || !ft_duplicates(ft_atoi(*str)))
				ft_error(stack_a);
			str++;
		}
	}
}
