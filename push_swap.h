/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:49:39 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/26 21:16:33 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
void	swap(t_list **src);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **src);
void	r_rotate(t_list **src);
void	sort_three(t_list **list);
void	chek_push_a_to_b(t_list **a, t_list **b);
void	chek_reception_b_from_a(t_list **a, t_list **b);
void	send_to_a(t_list **a, t_list **b);
void	sort(t_list **a);
#endif