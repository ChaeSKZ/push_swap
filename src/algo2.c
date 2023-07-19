/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:49:33 by jugingas          #+#    #+#             */
/*   Updated: 2023/03/13 13:30:55 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

t_piles	*find_top(t_piles *stock, int r_min, int r_max)
{
	int	i;
	int	r_moves;
	int	rr_moves;
	int	size;

	i = -1;
	r_moves = 1;
	rr_moves = 1;
	size = stock->size_a;
	while (++i <= stock->size_a / 2)
		if (stock->pile_a[i] >= r_min && stock->pile_a[i] <= r_max)
			break ;
	while (--i >= 0)
		r_moves++;
	while (--size > stock->size_a / 2)
		if (stock->pile_a[size] >= r_min && stock->pile_a[size] <= r_max)
			break ;
	while (++size <= stock->size_a)
		rr_moves++;
	return (move_opt(stock, r_moves, rr_moves));
}

int	is_bigger_all(int nb, int *pile, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb < pile[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_lower_all(int nb, int *pile, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb > pile[i])
			return (0);
		i++;
	}
	return (1);
}

t_piles	*push_top_b(t_piles *stock, int r_min, int r_max, int moves)
{
	if (moves > 1)
	{
		while (stock->pile_a[0] > stock->pile_b[0]
			&& !is_bigger_all(stock->pile_a[0], stock->pile_b, stock->size_b)
			&& !is_lower_all(stock->pile_a[0], stock->pile_b, stock->size_b))
			stock->pile_b = rotate(stock->pile_b, stock->size_b, "rb\n");
	}
	(void)r_min;
	(void)r_max;
	(void)moves;
	stock = push_b(stock);
	if (stock->pile_b[0] >= (r_max - ((r_max - r_min) / 2))
		&& stock->size_a + stock->size_b > 101)
	{
		if (stock->pile_a[0] > r_max || stock->pile_a[0] < r_min)
			stock = rrr_rotate(stock);
		else
			stock->pile_b = r_rotate(stock->pile_b, stock->size_b, "rrb\n");
	}
	return (stock);
}

t_piles	*push_back(t_piles *stock)
{
	int	temp;
	int	i;

	temp = -1;
	i = -1;
	while (++i < stock->size_b)
		if (stock->pile_b[i] > temp)
			temp = stock->pile_b[i];
	i = 0;
	while (stock->pile_b[i] != temp)
		i++;
	if (i <= stock->size_b / 2)
		while (stock->pile_b[0] != temp)
			stock->pile_b = rotate(stock->pile_b, stock->size_b, "rb\n");
	else
		while (stock->pile_b[0] != temp)
			stock->pile_b = r_rotate(stock->pile_b, stock->size_b, "rrb\n");
	stock = push_a(stock);
	return (stock);
}
