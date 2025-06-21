/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:24:31 by marvin            #+#    #+#             */
/*   Updated: 2025/06/07 09:36:49 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_overflow(long result, int next_digit, int sign)
{
	if (sign == 1 && result > (LONG_MAX - next_digit) / 10)
		return (-1);
	if (sign == -1 && result > (LONG_MAX - next_digit) / 10)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			i;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (ft_is_overflow(result, str[i], sign) != 1)
			return (ft_is_overflow(result, str[i], sign));
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
// #include <stdio.h>
// #include <string.h>

// int	main(int argc, char const *argv[])
// {
// 	(void)argc;
// 	printf("%d \n", ft_atoi(argv[1]));
// 	printf("%d \n", atoi(argv[1]));
// 	return (0);
// }
