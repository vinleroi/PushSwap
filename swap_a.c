/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:57:25 by aahadji           #+#    #+#             */
/*   Updated: 2025/02/16 11:47:14 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap_a(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_push_a(int *a, int *b)
{
	int *temp;
	
	if (!b)
		return ;
	if (!a)
		a[0] = b[0];
	recive_to_tab(&a, b[0]);
	send_to_tab(b);
	free (b); 

}