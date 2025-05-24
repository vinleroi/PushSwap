/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:45:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/05/24 17:05:49 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * print the list
 */
static void	print_list(t_list *list)
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

static int	numbers(int pos, char *arg, t_list **a)
{
	int	value;

	if (pos == 0 && ft_isdigit(arg))
	{
		value = ft_atoi(arg);
		if (error_check(a, value, pos, &arg))
			return (1);
		ft_lstadd_back(a, ft_lstnew(value));
	}
	else if (pos > 0 && ft_isdigit(arg) && ft_strlen(arg) > 0)
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

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	**a;
	char	**split_args;
	char	*parsed_args;

	head = NULL;
	a = &head;
	if (argc > 1)
	{
		parsed_args = parsed_entry(argv);
		while (parsed_args[i])
			sort(a);
		print_list(*a);
		ft_lstclear(a, free);
		ft_free_split(split_args);
	}
	return (0);
}

/**
 * sort the list
∑tree */
void	sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	while (*a)
	{
		push_best_element(a, &b);
		*a = (*a)->next;
	}
	push_back_to_a(a, &b);
	ft_lstclear(&b, free);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}
