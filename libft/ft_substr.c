/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:48:43 by aahadji           #+#    #+#             */
/*   Updated: 2025/05/22 23:08:11 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;
	size_t	size_s;

	if (!s)
		return (NULL);
	size_s = ft_strlen((char *)s);
	if (start >= size_s)
		len = 0;
	else if (len > size_s - start)
		len = size_s - start;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
