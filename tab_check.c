/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 09:35:32 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int ia, int ib, int sa, int sb)
{
	int	cost_a;
	int	cost_b;

	if (ia <= sa / 2)
		cost_a = ia;
	else
		cost_a = -(sa - ia);
	if (ib <= sb / 2)
		cost_b = ib;
	else
		cost_b = -(sb - ib);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		else
			return (ft_abs(cost_b));
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

int	find_cheapest_move(t_list *a, t_list *b, int *ia, int *ib)
{
	int	i;
	int	sa;
	int	sb;
	int	min_cost;
	int	tmp_cost;
	int	tmp_ib;

	sa = ft_lstsize(a);
	sb = ft_lstsize(b);
	min_cost = INT_MAX;
	i = 0;
	while (a)
	{
		tmp_ib = find_best_insert_position(b, a->content);
		tmp_cost = calculate_cost(i, tmp_ib, sa, sb);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			if (i <= sa / 2)
				*ia = i;
			else
				*ia = -(sa - i);
			if (tmp_ib <= sb / 2)
				*ib = tmp_ib;
			else
				*ib = -(sb - tmp_ib);
		}
		a = a->next;
		i++;
	}
	return (min_cost);
}

void	move_a(t_list **a, int *ia)
{
	if (*ia > 0)
	{
		rotate(a);
		ft_printf("ra\n");
		(*ia)--;
	}
	else if (*ia < 0)
	{
		r_rotate(a);
		ft_printf("rra\n");
		(*ia)++;
	}
}

void	move_b(t_list **b, int *ib)
{
	if (*ib > 0)
	{
		rotate(b);
		ft_printf("rb\n");
		(*ib)--;
	}
	else if (*ib < 0)
	{
		r_rotate(b);
		ft_printf("rrb\n");
		(*ib)++;
	}
}

void	move_to_position(t_list **a, t_list **b, int ia, int ib)
{
	while (ia > 0 && ib > 0)
	{
		rotate_both(a, b);
		ft_printf("rr\n");
		ia--;
		ib--;
	}
	while (ia < 0 && ib < 0)
	{
		r_rotate_both(a, b);
		ft_printf("rrr\n");
		ia++;
		ib++;
	}
	while (ia)
		move_a(a, &ia);
	while (ib)
		move_b(b, &ib);
}
