/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:18:33 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:52:47 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *temp;
	size_t total_size;
	size_t i;

	total_size = count * size;
	if (size != 0 && total_size / size != count)
		return (NULL);
	temp = (unsigned char *)malloc(total_size);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		temp[i] = '\0';
		i++;
	}
	return ((void *)temp);
}