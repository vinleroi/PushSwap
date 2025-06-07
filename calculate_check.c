/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:23:09 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:49:16 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_of_max(t_list *stack)
{
	int		max;
	int		index;
	int		i;
	t_list	*tmp;

	max = stack->content;
	index = 0;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

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

int	find_best_insert_position(t_list *b, int value)
{
	int		i;
	int		pos;
	int		min_diff;
	int		diff;
	t_list	*tmp;

	i = 0;
	pos = 0;
	min_diff = INT_MAX;
	tmp = b;
	while (tmp)
	{
		diff = tmp->content - value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (min_diff == INT_MAX)
		pos = index_of_max(b);
	return (pos);
}

void	push_best_element(t_list **a, t_list **b)
{
	int	index_a;
	int	index_b;

	if (!*a)
		return ;
	if (!*b)
	{
		push(a, b);
		ft_printf("pb\n");
		return ;
	}
	find_cheapest_move(*a, *b, &index_a, &index_b);
	move_to_position(a, b, index_a, index_b);
	push(a, b);
	ft_printf("pb\n");
}

void	push_back_to_a(t_list **a, t_list **b)
{
	int	max_i;
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b);
		max_i = index_of_max(*b);
		while (max_i != 0)
		{
			if (max_i <= size / 2)
			{
				rotate_b(b);
				max_i--;
			}
			else
			{
				r_rotate_b(b);
				max_i++;
				if (max_i == size)
					max_i = 0;
			}
		}
		push(b, a);
		ft_printf("pa\n");
	}
}
