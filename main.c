/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:45:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/03/29 17:11:58 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%d ", list->content);
		list = list->next;
	}
	ft_printf("\n");
}
/**
 * oublie pas de changer la façon de vérifier ton nombre  ^^
 */
static t_list	*check_argv(int argc, char **argv)
{
	int		i;
	int		temp;
	t_list	*a;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		if (ft_isdigit(argv[i]))
		{
			temp = ft_atoi(argv[i]);
			if (temp == -1 && !(ft_strcmp(argv[++i], ft_itoa(temp)))
				&& !ft_check_dupe(a, temp))
				return (ft_printf("Error in the argument sems to be overflow or you have dupes T.T\n"),
					ft_lstclear(&a, free), NULL);
			else
				ft_lstadd_back(&a, ft_lstnew(temp));
		}
		else
			return (ft_printf("Error in the argument sems not to be a digit  T.T\n"),
				ft_lstclear(&a, free), NULL);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;

	if (argc > 1)
	{
		a = check_argv(argc, argv);
		if (a == NULL)
			ft_printf("Error in the argument sems to be null T.T\n");
		else
		{
			sort(&a);
			print_list(a);
		}
		ft_lstclear(&a, free);
	}
	return (0);
}

void	sort(t_list **a)
{
	t_list	*b;
	int		temp;

	b = NULL;
	chek_push_a_to_b(a, &b);
	ft_lstclear(&b, free);
}
