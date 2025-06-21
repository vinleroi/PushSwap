/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:01:58 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:51:31 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t	size;
	size_t	i;
	char	*temp;

	size = ft_strlen((char *)s1);
	temp = (char *)malloc(sizeof(char) * size + 1);
	if (!temp)
		return (0);
	i = 0;
	while (i < size && s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
