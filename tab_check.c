/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/26 21:20:01 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **list)
{
	int	max;

	max = ft_lstmax(list);
	if ((*list)->content == max)
		rotate(list);
	if (ft_lstsize(*list) == 3 && (*list)->next->content == max)
		r_rotate(list);
	if ((*list)->next->content == ft_lstmin(*list))
		swap(list);
}

void	chek_push_a_to_b(t_list **a, t_list **b)
{
	while (ft_lstsize(a) > 0)
	{
		if ((*a)->content > ft_lstlast(a)->content)
		{
			r_rotate(a);
			ft_printf("rra\n");
		}
		else if ((*a)->content > (*a)->next->content)
		{
			swap(a);
			ft_printf("sa\n");
		}
		chek_reception_b_from_a(b, a);
	}
	send_to_a(a, b);
}

void	chek_reception_b_from_a(t_list **b, t_list **a)
{
	if ((*a)->content < (*b)->content)
	{
		while ((*a)->content < (*b)->content)
		{
			rotate(b);
			ft_printf("rb\n");
		}
		push(a, b);
		ft_printf("pb\n");
	}
	else if ((*a)->content > (*b)->content && (*a)->content > ft_lstlast(*b))
	{
		while ((*a)->content > ft_lstlast(*b))
		{
			r_rotate(b);
			ft_printf("rrb\n");
		}
		push(a, b);
		ft_printf("pb\n");
	}
	if ((*a)->content > (*b)->content)
	{
		push(a, b);
		ft_printf("pb\n");
	}
}
void	send_to_a(t_list **a, t_list **b)
{
	while (ft_lstsize(b) > 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}