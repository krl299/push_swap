/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:27:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/03/30 13:53:59 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//
static long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

//
static int	ft_is_int(char *str)
{
	long long	n;

	n = ft_atoll(str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return (1);
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
			if (!ft_isnum(*str) || !ft_dupes(ft_atoi(*str)) || !ft_is_int(*str))
				ft_arg_error(stack_a);
			else
				ft_stack_addback(ft_stack_newnode(ft_atoi(*str)), stack_a);
			free(*str);
			str++;
		}
	}
}
