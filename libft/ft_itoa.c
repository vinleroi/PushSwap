/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:48:01 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:52:08 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_tab(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	put_nmbr(char *tab, int n, size_t len)
{
	tab[len] = 0;
	if (n == 0)
		tab[0] = 0;
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		tab[--len] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		size_tab;

	if (n == 0)
		return (ft_strdup("0"));
	if (!n)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size_tab = len_tab(n);
	temp = (char *)malloc(sizeof(char) * (size_tab + 1));
	if (!temp)
		return (NULL);
	put_nmbr(temp, n, size_tab);
	return (temp);
}
