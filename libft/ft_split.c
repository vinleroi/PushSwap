/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:57:14 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:53:28 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_tab(const char *s, char c)
{
	size_t	len;
	int		in_word;

	len = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			len++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (len);
}

static size_t	len_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **tab, size_t i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (NULL);
}

static size_t	find_word_index(const char *s, char c, size_t start_pos)
{
	while (s[start_pos] == c && s[start_pos])
		start_pos++;
	return (start_pos);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	size_t	i;
	size_t	index;
	size_t	size_tab;

	if (!s)
		return (NULL);
	size_tab = len_tab(s, c);
	temp = (char **)malloc(sizeof(char *) * (size_tab + 1));
	if (!temp)
		return (NULL);
	i = 0;
	index = 0;
	while (i < size_tab)
	{
		index = find_word_index((char *)s, c, index);
		temp[i] = ft_substr(s, index, len_word(&s[index], c));
		if (!temp[i])
			return (ft_free(temp, i));
		index += len_word((char *)&s[index], c);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char **result;
	int i = 0;
	char str[] = "je kmw odlaksd ekmdelasedjklansk   ";

	result = ft_split(str, ' ');
	while (result[i])
	{
		printf("Word %d: %s\n", i, result[i]);
		i++;
	}

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);

	return (0);
}*/