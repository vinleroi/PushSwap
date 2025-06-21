/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:57:18 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:55:34 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (!c[i])
		return (1);
	while ((c[i] >= 48 && c[i] <= 57) || c[i] == 45 || c[i] == 43)
		i++;
	return ((i - ft_strlen(c)));
}

int	ft_check_dupe(t_list *a, int content)
{
	while (a)
	{
		if (a->content == content)
			return (1);
		a = a->next;
	}
	return (0);
}
