/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/05/24 15:02:22 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_move(t_list *a, t_list *b, int *index_a, int *index_b)
{
	int	i;
	int	size_a;
	int	size_b;
	int	min_cost;
	int	cost;

	i = 0;
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	min_cost = INT_MAX;
	while (a)
	{
		*index_b = find_best_insert_position(b, a->content);
		cost = calculate_cost(i, *index_b, size_a, size_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			*index_a = i;
		}
		a = a->next;
		i++;
	}
	return (min_cost);
}

static void	move_a(t_list **a, int *ia, int size)
{
	if (*ia > 0 && *ia <= size / 2)
	{
		rotate(a);
		ft_printf("ra\n");
		(*ia)--;
	}
	else if (*ia > size / 2)
	{
		r_rotate(a);
		ft_printf("rra\n");
		(*ia)++;
		if (*ia == size)
			*ia = 0;
	}
}

static void	move_b(t_list **b, int *ib, int size)
{
	if (*ib > 0 && *ib <= size / 2)
	{
		rotate(b);
		ft_printf("rb\n");
		(*ib)--;
	}
	else if (*ib > size / 2)
	{
		r_rotate(b);
		ft_printf("rrb\n");
		(*ib)++;
		if (*ib == size)
			*ib = 0;
	}
}

void	move_to_position(t_list **a, t_list **b, int ia, int ib)
{
	int	sa;
	int	sb;

	sa = ft_lstsize(*a);
	sb = ft_lstsize(*b);
	while (ia > 0 || ib > 0)
	{
		move_a(a, &ia, sa);
		move_b(b, &ib, sb);
	}
}
