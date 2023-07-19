/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:21:01 by jugingas          #+#    #+#             */
/*   Updated: 2022/12/02 11:53:20 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	*rotate(int	*pile, int size, char *str)
{
	int	i;
	int	temp;

	temp = pile[0];
	i = 0;
	while (i < size - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = temp;
	write(1, str, ft_strlen(str));
	return (pile);
}

t_piles	*rr_rotate(t_piles *stock)
{
	stock->pile_a = rotate(stock->pile_a, stock->size_a, "");
	stock->pile_b = rotate(stock->pile_b, stock->size_b, "");
	write(1, "rr\n", 3);
	return (stock);
}

int	*r_rotate(int *pile, int size, char *str)
{
	int	i;
	int	temp;

	temp = pile[size - 1];
	i = size - 1;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[i] = temp;
	write(1, str, ft_strlen(str));
	return (pile);
}

t_piles	*rrr_rotate(t_piles *stock)
{
	stock->pile_a = r_rotate(stock->pile_a, stock->size_a, "");
	stock->pile_b = r_rotate(stock->pile_b, stock->size_b, "");
	write(1, "rrr\n", 4);
	return (stock);
}
