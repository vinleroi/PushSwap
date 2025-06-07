/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:27:45 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:50:11 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_b(t_list **b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	r_rotate_a(t_list **a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	rotate_a(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	r_rotate_both(t_list **a, t_list **b)
{
	r_rotate(a);
	r_rotate(b);
}
