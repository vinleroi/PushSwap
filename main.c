/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:45:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/05 23:15:28 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * print the list
 */
void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%d ", list->content);
		list = list->next;
	}
	ft_printf("\n");
}

static int	error_check(t_list **a, int value, int i, char **argv)
{
	char	*str_value;

	str_value = ft_itoa(value);
	if (!str_value)
		return (1);
	if (*a && ft_check_dupe(*a, value))
	{
		ft_printf("Error: seems you have duplicates T.T\n");
		ft_lstclear(a, free);
		free(str_value);
		return (1);
	}
	if (value == -1 && ft_strcmp(argv[i], str_value) != 0)
	{
		ft_printf("Error: argument doesn't seem to be a valid digit T.T\n");
		ft_lstclear(a, free);
		free(str_value);
		return (1);
	}
	free(str_value);
	return (0);
}
/**
 * list of numbers create the list of all numbers
 */
int	numbers(int pos, char *arg, t_list **a)
{
	int	value;

	if (pos == 0 && !ft_isdigit(arg))
	{
		value = ft_atoi(arg);
		if (error_check(a, value, pos, &arg))
			return (1);
		ft_lstadd_back(a, ft_lstnew(value));
	}
	else if (pos > 0 && !ft_isdigit(arg) && ft_strlen(arg) > 0)
	{
		value = ft_atoi(arg);
		if (error_check(a, value, pos, &arg))
			return (1);
		ft_lstadd_back(a, ft_lstnew(value));
	}
	else
	{
		ft_printf("Error: argument doesn't seem to be a valid digit T.T\n");
		return (1);
	}
	return (0);
}
static void	complete_list(t_list **a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (numbers(i, args[i], a))
		{
			ft_free_split(args);
			ft_lstclear(a, free);
			ft_printf("Error: invalid argument T.T\n");
			exit(1);
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	**a;
	char	**split_args;

	head = NULL;
	a = &head;
	if (argc > 1)
	{
		split_args = flatten_arguments(argc, argv);
		if (!split_args)
		{
			ft_printf("Error: memory allocation failed T.T\n");
			return (1);
		}
		complete_list(a, split_args);
		sort(a);
		ft_lstclear(a, free);
		ft_free_split(split_args);
	}
	return (0);
}
