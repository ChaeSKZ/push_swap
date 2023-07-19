/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:25:22 by jugingas          #+#    #+#             */
/*   Updated: 2023/07/05 13:03:22 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_piles	*move_opt(t_piles *stock, int r_moves, int rr_moves)
{
	if (r_moves <= rr_moves)
	{
		while (--r_moves > 0)
		{
			if (r_moves == 1 && stock->pile_a[1] > stock->pile_b[0])
				stock = rr_rotate(stock);
			else
				rotate(stock->pile_a, stock->size_a, "ra\n");
		}
	}
	else
		while (--rr_moves > 0)
			r_rotate(stock->pile_a, stock->size_a, "rra\n");
	return (stock);
}

void	free_stock(t_piles *stock)
{
	free(stock->pile_a);
	free(stock->pile_b);
	free(stock);
}
