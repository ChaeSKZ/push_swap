/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:11:51 by jugingas          #+#    #+#             */
/*   Updated: 2023/03/16 14:29:00 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	ft_print_error(t_piles *stock)
{
	write(2, "Error\n", 6);
	free_stock(stock);
	exit(-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	*simplify(int *tab, int size)
{
	int	*new;
	int	i;
	int	moved;
	int	temp;
	int	ex_temp;

	new = malloc(sizeof(int) * size);
	if (!new || !tab)
		return (NULL);
	moved = 0;
	ex_temp = INT_MIN;
	while (moved != size)
	{
		i = -1;
		temp = INT_MAX;
		while (++i < size)
			if ((tab[i] == INT_MIN && moved == 0)
				|| (tab[i] < temp && tab[i] > ex_temp))
				temp = tab[i];
		ex_temp = temp;
		new = change_value(tab, temp, new, moved);
		moved++;
	}
	free(tab);
	return (new);
}

t_piles	*call_sort(t_piles *stock)
{
	if (stock->size_a == 2 && !check_pile(stock->pile_a, stock->size_a))
		swap(stock->pile_a, stock->size_a, "sa\n");
	else if (stock->size_a == 3)
		stock->pile_a = sort_3(stock->pile_a, stock->size_a);
	else if (stock->size_a <= 5)
		stock = sort_5(stock);
	else if (stock->size_a > 5 && stock->size_a < 101)
		stock = insertion(stock, 5);
	else if (stock->size_a >= 101)
		stock = insertion(stock, 12);
	return (stock);
}
