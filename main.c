/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:45:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/17 16:51:06 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	if (argc > 1)
	{
		a = check_args(argc, argv);

		if (a == NULL)
		{
		}

		if (ft_lstsize(a) > 1 && !is_sorted(a))
			sort(&a, &b);

		clean(&a, &b);
	}
	return (0);
}