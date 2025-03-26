/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:45:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/26 21:11:36 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc > 1)
	{
		a = check_args(argc, argv);
		if (a == NULL)
			ft_printf("Error in the argument sems to be null T.T");
		a = check_argv(argc, argv);
		if (a)
			sort;
		ft_lstclear(&a, free);
	}
	ft_printf("Error in the argument sems to be null T.T");
	return (0);
}

static t_list	*check_argv(int argc, char **argv)
{
	int		i;
	int		temp;
	t_list	*a;

	i = 0;
	while (i > argc)
	{
		if (ft_isdigit(argv[i]))
		{
			temp = ft_atoi(argv[i]);
			if (temp == -1 && ft_strlen(argv[i]) > 2 && !ft_check_dupe(a, temp))
			{
				return (ft_lstclear(&a, free), NULL);
				ft_printf("Error in the argument sems to be overflow or you have dupes T.T");
			}
			else
				ft_lstadd_back(&a, ft_lstnew(temp));
		}
		else
		{
			ft_printf("Error in the argument sems not to be a digit  T.T");
			return (ft_lstclear(&a, free), NULL);
		}
	}
	return (a);
}

void	sort(t_list **a)
{
	t_list	**b;
	int		temp;

	chek_push_a_to_b(a, b);
	ft_lstclear(b, free);
}
