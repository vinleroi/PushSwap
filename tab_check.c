/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:58:44 by aahadji           #+#    #+#             */
/*   Updated: 2025/02/19 00:30:59 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	send_to_tab(int *tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (tab[i])
	{
		tab[j] = tab[i];
		i++;
		j++;
	}
	tab[i] = 0;
}

void	recive_to_tab(int *tab, int i)
{
	int len;
	int j;
	int temp;
	int temp_second;

	len = ft_strlen(tab);
	j = 0;
	temp_second = 0;
	temp = tab[j];
	tab[j] = i;
	j++;
	while (tab[j])
	{
		temp_second = tab[j];
		tab[j] = temp;
		temp = temp_second;
		j++;
	}
}