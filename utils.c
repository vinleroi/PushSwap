/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:45:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/05/30 17:28:37 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * count the numbers of numbers in the argument
 */
static int	ft_count_word(const char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ')
			in_word = 0;
		str++;
	}
	return (count);
}

static int	ft_count_args(char **args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (args[i])
	{
		count += ft_count_word(args[i]);
		i++;
	}
	return (count);
}

/*
** fonction that return a char ** that is the arguments in one string
*/
char	**flatten_arguments(int argc, char **argv)
{
	int		i;
	int		k;
	int		total;
	char	**temp;
	char	**flat;
	int		word_count;

	flat = (char **)ft_calloc(sizeof(char *), (ft_count_args(argv) + 1));
	if (!flat)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		temp = split(argv[i], ' ');
		word_count = 0;
		while (temp[word_count])
		{
			flat[k++] = temp[word_count];
			word_count++;
		}
		free(temp);
		i++;
	}
	return (flat);
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
	int i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}