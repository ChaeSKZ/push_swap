/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugingas <jugingas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:12:04 by jugingas          #+#    #+#             */
/*   Updated: 2023/07/05 13:03:15 by jugingas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_piles
{
	int	*pile_a;
	int	*pile_b;
	int	size_a;
	int	size_b;
}				t_piles;

void	ft_print_error(t_piles *stock);
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr, t_piles *stock);
int		ft_strcmp(char *s1, char *s2);

int		*swap(int *pile, int size, char *str);
int		*rotate(int	*pile, int size, char *str);
int		*r_rotate(int *pile, int size, char *str);
t_piles	*s_swap(t_piles *stock);
t_piles	*push_a(t_piles *stock);
t_piles	*push_b(t_piles *stock);
t_piles	*rr_rotate(t_piles *stock);
t_piles	*rrr_rotate(t_piles *stock);

int		*simplify(int *tab, int size);
int		*change_value(int *tab, int value, int *new, int new_value);
int		check_pile(int *pile, int size);
int		check_sorted(int *pile, int size);
void	free_stock(t_piles *stock);
t_piles	*call_sort(t_piles *stock);
int		*sort_3(int *pile, int size);
t_piles	*sort_5(t_piles *stock);
t_piles	*insertion(t_piles *stock, int len);
t_piles	*find_top(t_piles *stock, int r_min, int r_max);
t_piles	*push_top_b(t_piles *stock, int r_min, int r_max, int moves);
t_piles	*move_opt(t_piles *stock, int r_moves, int rr_moves);
t_piles	*push_back(t_piles *stock);

#endif
