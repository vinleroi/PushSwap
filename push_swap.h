/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:49:39 by aahadji           #+#    #+#             */
/*   Updated: 2025/02/16 12:05:01 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft/libft.h>
# include <printf/ft_printf.h>
void	ft_swap_a(int *a, int *b);
void	ft_swap_b(int *a, int *b);
void	ft_swap_ab(int *a, int *b);
void	ft_push_a(int *a, int *b);
void	ft_push_b(int *a, int *b);
void	ft_rotate_a(int *a, int *b);
void	ft_rotate_b(int *a, int *b);
void	ft_rotate_ab(int *a, int *b);
void	ft_reverse_rotate_a(int *a, int *b);
void	ft_reverse_rotate_b(int *a, int *b);
void	ft_reverse_rotate_ab(int *a, int *b);
ssize_t	ft_strlen(void *tab);
int		*send_to_tab(int *tab);
#endif