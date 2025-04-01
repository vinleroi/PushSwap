/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/04/01 09:16:53 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_b(t_list **b, t_list **a)
{
	t_list	*new_node;
	t_list	*tmp;

	*b = NULL;
	new_node = ft_lstnew((*a)->content);
	if (!new_node)
		return ;
	ft_lstadd_back(b, new_node);
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	ft_printf("pb\n");
}
static void	check_min_in_b(t_list **b, t_list **a)
{
	int	min;

	if ((*a)->content < (*b)->content)
	{
		min = ft_lstmin(*b);
		while (min != (*b)->content && (*a)->content < (*b)->content)
		{
			rotate(b);
			ft_printf("rb\n");
		}
	}
	push(a, b);
	ft_printf("pb\n");
	swap(b);
	ft_printf("sb\n");
}
void	chek_push_a_to_b(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 1)
	{
		if ((*a)->content > ft_lstlast(*a)->content)
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
	int	z;

	if (!(*b))
		return (init_b(b, a));
	if ((*a)->content < (*b)->content)
		check_min_in_b(b, a);
	else if ((*a)->content > (*b)->content
		&& (*a)->content > ft_lstlast(*b)->content)
	{
		z = ft_lstmax(*b);
		while (z != (*b)->content && (*a)->content > ft_lstlast(*b)->content)
		{
			r_rotate(b);
			ft_printf("rrb\n");
		}
	}
	push(a, b);
	ft_printf("pb\n");
}

void	send_to_a(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) > 0)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}
