/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:15:07 by jugingas          #+#    #+#             */
/*   Updated: 2023/07/05 13:00:15 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_pile(int *pile, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*sort_3(int *pile, int size)
{
	if (pile[0] > pile[1] && pile[1] < pile[2] && pile[2] > pile[0])
		swap(pile, size, "sa\n");
	else if (pile[0] > pile[1] && pile[1] < pile[2] && pile[2] < pile[0])
		rotate(pile, size, "ra\n");
	else if (pile[0] < pile[1] && pile[1] > pile[2] && pile[2] < pile[0])
		r_rotate(pile, size, "rra\n");
	else if (pile[0] > pile[1] && pile[1] > pile[2])
	{
		swap(pile, size, "sa\n");
		r_rotate(pile, size, "rra\n");
	}
	else if (pile[0] < pile[1] && pile[1] > pile[2] && pile[2] > pile[0])
	{
		swap(pile, size, "sa\n");
		rotate(pile, size, "ra\n");
	}
	return (pile);
}

t_piles	*find_lowest(t_piles *stock)
{
	int	i;
	int	temp;
	int	t_index;

	i = 1;
	t_index = 0;
	temp = stock->pile_a[0];
	while (i < stock->size_a)
	{
		if (stock->pile_a[i] < temp)
		{
			temp = stock->pile_a[i];
			t_index = i;
		}
		i++;
	}
	if (t_index >= stock->size_a / 2)
		while (stock->pile_a[0] != temp)
			r_rotate(stock->pile_a, stock->size_a, "rra\n");
	else
		while (stock->pile_a[0] != temp)
			rotate(stock->pile_a, stock->size_a, "ra\n");
	stock = push_b(stock);
	return (stock);
}

t_piles	*sort_5(t_piles *stock)
{
	if (stock->size_a == 4)
	{
		stock = find_lowest(stock);
		stock->pile_a = sort_3(stock->pile_a, stock->size_a);
		stock = push_a(stock);
	}
	else
	{
		stock = find_lowest(stock);
		stock = find_lowest(stock);
		stock->pile_a = sort_3(stock->pile_a, stock->size_a);
		stock = push_a(stock);
		stock = push_a(stock);
	}
	return (stock);
}

t_piles	*insertion(t_piles *stock, int len)
{
	int	chunk;
	int	moves;
	int	size;
	int	r_min;
	int	r_max;

	moves = 0;
	chunk = 0;
	size = stock->size_a;
	while (stock->size_a > 0)
	{
		r_min = size / len * chunk;
		r_max = size / len * (chunk + 1) - 1;
		stock = find_top(stock, r_min, r_max);
		stock = push_top_b(stock, r_min, r_max, moves);
		moves++;
		if (moves == size / len)
		{
			chunk++;
			moves = 0;
		}
	}
	while (stock->size_b > 0)
		stock = push_back(stock);
	return (stock);
}
