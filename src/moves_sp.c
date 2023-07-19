/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:11:57 by jugingas          #+#    #+#             */
/*   Updated: 2022/12/02 11:24:02 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	*swap(int *pile, int size, char *str)
{
	int	temp;

	if (size <= 1)
		return (pile);
	temp = pile[0];
	pile[0] = pile[1];
	pile[1] = temp;
	write(1, str, ft_strlen(str));
	return (pile);
}

t_piles	*s_swap(t_piles *stock)
{
	int	temp;

	if (stock->size_a >= 2)
	{
		temp = stock->pile_a[0];
		stock->pile_a[0] = stock->pile_a[1];
		stock->pile_a[1] = temp;
	}
	else
		write(1, "bug sa -> ", 10);
	if (stock->size_b >= 2)
	{
		temp = stock->pile_b[0];
		stock->pile_b[0] = stock->pile_b[1];
		stock->pile_b[1] = temp;
	}
	else
		write(1, "bug sb -> ", 10);
	write(1, "ss\n", 3);
	return (stock);
}

int	*compact_pile(int *pile, int size)
{
	int	i;

	i = 0;
	while (i <= size - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	return (pile);
}

t_piles	*push_a(t_piles *stock)
{
	int	i;

	i = stock->size_a;
	if (stock->size_b >= 1)
	{
		while (i > 0)
		{
			stock->pile_a[i] = stock->pile_a[i - 1];
			i--;
		}
		stock->pile_a[0] = stock->pile_b[0];
		stock->size_a++;
		stock->size_b--;
		stock->pile_b = compact_pile(stock->pile_b, stock->size_b);
		write(1, "pa\n", 3);
	}
	else
		write(1, "bug -> pa\n", 10);
	return (stock);
}

t_piles	*push_b(t_piles *stock)
{
	int	i;

	i = stock->size_b;
	if (stock->size_a >= 1)
	{
		while (i > 0)
		{
			stock->pile_b[i] = stock->pile_b[i - 1];
			i--;
		}
		stock->pile_b[0] = stock->pile_a[0];
		stock->size_b++;
		stock->size_a--;
		stock->pile_a = compact_pile(stock->pile_a, stock->size_a);
		write(1, "pb\n", 3);
	}
	else
		write(1, "bug -> pb\n", 10);
	return (stock);
}
