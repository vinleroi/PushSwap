/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:00:01 by aahadji           #+#    #+#             */
/*   Updated: 2025/05/22 21:03:34 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmax(t_list *tab)
{
	int	max;

	if (!tab)
		return (0);
	max = tab->content;
	tab = tab->next;
	while (tab)
	{
		if (max < tab->content)
			max = tab->content;
		tab = tab->next;
	}
	return (max);
}

int	ft_lstmin(t_list *tab)
{
	int	min;

	if (!tab)
		return (0);
	min = tab->content;
	tab = tab->next;
	while (tab)
	{
		if (min > tab->content)
			min = tab->content;
		tab = tab->next;
	}
	return (min);
}
