/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:11:54 by jugingas          #+#    #+#             */
/*   Updated: 2023/07/05 12:59:53 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	check_rep(int *pile, int size)
{
	int	i;
	int	n;

	i = 0;
	while (i < size)
	{
		n = 1;
		while (i + n < size)
		{
			if (pile[i] == pile[i + n])
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

static int	check_format(char **av)
{
	int	i;
	int	n;

	i = 1;
	while (av[i])
	{
		n = 0;
		if (ft_strlen(av[i]) == 0)
			return (0);
		while (is_whitespace(av[i][n]) && av[i][n])
			n++;
		if (av[i][n] == '-' || av[i][n] == '+')
			n++;
		if ((ft_strcmp(av[i] + n, "2147483647") > 0
				&& (n == 0 || av[i][n - 1] != '-'))
		|| (ft_strcmp(av[i] + n, "2147483648") > 0
				&& (n != 0 && av[i][n - 1] == '-')))
			return (0);
		while (av[i][n])
			if (av[i][n] > '9' || av[i][n++] < '0')
				return (0);
		i++;
	}
	return (1);
}

static t_piles	*get_args(t_piles *stock, char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	stock->size_a = i - 1;
	stock->size_b = 0;
	stock->pile_a = malloc(sizeof(int) * (i - 1));
	stock->pile_b = malloc(sizeof(int) * (i - 1));
	if (!stock->pile_a || !stock->pile_b)
		return (NULL);
	i = 1;
	while (av[i])
	{
		stock->pile_a[i - 1] = ft_atoi(av[i], stock);
		i++;
	}
	return (stock);
}

int	main(int ac, char **av)
{
	t_piles	*stock;

	(void)ac;
	stock = malloc(sizeof(t_piles));
	stock = get_args(stock, av);
	if (!check_format(av))
		ft_print_error(stock);
	if (stock == NULL || !check_rep(stock->pile_a, stock->size_a))
		ft_print_error(stock);
			stock->pile_a = simplify(stock->pile_a, stock->size_a);
	if (!stock->pile_a)
		ft_print_error(stock);
	if (check_pile(stock->pile_a, stock->size_a))
	{
		free_stock(stock);
		return (0);
	}
	stock = call_sort(stock);
	free_stock(stock);
	return (0);
}
