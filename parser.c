/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/24 11:58:03 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if the given string is a number
int	ft_isnum(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || (str[0] == '+' && str[1]))
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

//	Search if exist the most value bit
int	ft_dupes(unsigned int nb)
{
	static char	map[5368709912];

	if (!(map[nb / 8] >> (7 - (nb % 8)) & 1))
		map[nb / 8] = map[nb / 8] | 1 << (7 - (nb % 8));
	else
		return (0);
	return (1);
}

// Case of a error
void	ft_arg_error(t_stack **stack)
{
	ft_clearstack(stack);
	write(2, "Error\n", 6);
	exit(0);
}

// Check that arg format is correct and add each int to the stack a
void	ft_check_arg(char **arg, t_stack **stack_a)
{
	int		i;
	char	**str;

	i = 0;
	while (arg[++i])
	{
		str = ft_split(arg[i], ' ');
		if (!*str)
			ft_arg_error(stack_a);
		while (*str)
		{
			if (!ft_isnum(*str) || !ft_dupes(ft_atoi(*str)))
				ft_arg_error(stack_a);
			else
				ft_stack_addback(ft_stack_newnode(ft_atoi(*str)), stack_a);
			free(*str);
			str++;
		}
	}
}
