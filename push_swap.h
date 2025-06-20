/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:49:39 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:30:48 by aahadji          ###   ########.fr       */
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
void	rotate_both(t_list **a, t_list **b);
void	r_rotate_both(t_list **a, t_list **b);

void	push_best_element(t_list **a, t_list **b);
void	move_to_position(t_list **a, t_list **b, int index_a, int index_b);
int		find_cheapest_move(t_list *a, t_list *b, int *best_index_a,
			int *best_index_b);
int		calculate_cost(int index_a, int index_b, int size_a, int size_b);
int		find_best_insert_position(t_list *b, int value);
void	send_to_a(t_list **a, t_list **b);
void	push_back_to_a(t_list **a, t_list **b);

void	sort(t_list **a);

int		ft_count_args(char **args);
void	ft_free_split(char **tab);

char	*parsed_entry(char **entry);
int		numbers(int pos, char *arg, t_list **a);

char	**flatten_arguments(int argc, char **argv);

void	print_list(t_list *list);
void	rotate_b(t_list **b);
void	r_rotate_b(t_list **b);
void	rotate_a(t_list **a);
void	r_rotate_a(t_list **a);
#endif