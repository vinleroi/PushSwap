/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/22 10:09:23 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
}

void	chek_reception_b_from_a(t_list **b)
{
	if ((*b)->content < (*b)->next->content)
	{
		swap(b);
		ft_printf("sb\n");
	}
	else if ()
}

static int	reverseRotate(t_list **a)
{
	int len;
	int min;
	int pos;

	min = ft_lstmin(*a);
}