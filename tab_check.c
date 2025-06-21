/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/21 22:42:41 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_best_indices(int i, int tmp_ib, t_sizes sizes,
		t_indices *idx)
{
	if (i <= sizes.sa / 2)
		idx->ia = i;
	else
		idx->ia = -(sizes.sa - i);
	if (tmp_ib <= sizes.sb / 2)
		idx->ib = tmp_ib;
	else
		idx->ib = -(sizes.sb - tmp_ib);
}

int	find_cheapest_move(t_list *a, t_list *b, t_indices *idx)
{
	int		i;
	int		min_cost;
	int		tmp_cost;
	int		tmp_ib;
	t_sizes	sizes;

	sizes.sa = ft_lstsize(a);
	sizes.sb = ft_lstsize(b);
	min_cost = INT_MAX;
	i = 0;
	while (a)
	{
		tmp_ib = find_best_insert_position(b, a->content);
		tmp_cost = calculate_cost(i, tmp_ib, sizes.sa, sizes.sb);
		if (tmp_cost < min_cost)
		{
			min_cost = tmp_cost;
			update_best_indices(i, tmp_ib, sizes, idx);
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
		rotate_a(a);
		(*ia)--;
	}
	else if (*ia < 0)
	{
		r_rotate_a(a);
		(*ia)++;
	}
}

void	move_b(t_list **b, int *ib)
{
	if (*ib > 0)
	{
		rotate_b(b);
		(*ib)--;
	}
	else if (*ib < 0)
	{
		r_rotate_b(b);
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
