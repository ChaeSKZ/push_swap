/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:15:26 by jugingas          #+#    #+#             */
/*   Updated: 2022/12/06 13:30:32 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*change_value(int *tab, int value, int *new, int new_value)
{
	int	i;

	i = 0;
	while (tab[i] != value)
		i++;
	new[i] = new_value;
	return (new);
}
