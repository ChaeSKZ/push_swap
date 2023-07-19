/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:30 by jugingas          #+#    #+#             */
/*   Updated: 2023/03/16 14:28:41 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

const char	*check_blank(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\t')
		i++;
	return (nptr + i);
}

void	check_int_max(long int nb, t_piles *stock)
{
	if (nb > INT_MAX || nb < INT_MIN)
		ft_print_error(stock);
}

int	ft_atoi(const char *nptr, t_piles *stock)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	nptr = check_blank(nptr);
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			sign = -1;
		i = 1;
	}
	while (nptr[i] == '0')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		result += nptr[i] - 48;
		i++;
		if (ft_isdigit(nptr[i]))
			result *= 10;
	}
	check_int_max(result * sign, stock);
	return (result * sign);
}
