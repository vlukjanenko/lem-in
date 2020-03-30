/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:01:53 by majosue           #+#    #+#             */
/*   Updated: 2019/09/16 15:45:55 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	char	digit;
	int		sign;
	long	over;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||\
*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = 44 - *str;
		str++;
	}
	while ((digit = *str++) != '\0' && digit >= '0' && digit <= '9')
	{
		over = result;
		result = result * 10 + digit - '0';
		if (over > result && sign == -1)
			return (0);
		if (over > result && sign == 1)
			return (-1);
	}
	return (sign * result);
}
