/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:57:25 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/27 17:35:01 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **src)
{
	int	temp;

	if (*src && (*src)->next)
	{
		temp = (*src)->content;
		(*src)->content = (*src)->next->content;
		(*src)->next->content = temp;
	}
}

void	push(t_list **src, t_list **dst)
{
	ft_lstadd_front(dst, ft_lstnew((*src)->content));
}

void	rotate(t_list **src)
{
	t_list	*first;
	t_list	*last;

	if (src && (*src)->next)
	{
		first = *src;
		last = ft_lstlast(*src);
		*src = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	r_rotate(t_list **src)
{
	t_list *temp;
	t_list *last;

	if (src && (*src)->next)
	{
		last = *src;
		while (last->next)
		{
			temp = last;
			last = last->next;
		}
		temp->next = NULL;
		last->next = *src;
		*src = last;
	}
}