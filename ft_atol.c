/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:24:17 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/12 23:24:17 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limits(long num, int sign)
{
	if ((sign == 1 && num > 2147483647)
		|| (sign == -1 && (-num) < -2147483648))
		return (0);
	return (1);
}

static int	handle_sign(const char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			return (*i += 1, -1);
		*i += 1;
	}
	return (1);
}

int	ft_atol(const char *str, long *result)
{
	int		sign;
	long	num;
	int		i;

	i = 0;
	num = 0;
	sign = handle_sign(str, &i);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = (num * 10) + (str[i] - '0');
		if (!check_limits(num, sign))
			return (0);
		i++;
	}
	*result = num * sign;
	return (1);
}
