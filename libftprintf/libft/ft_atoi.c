/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:40:44 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long	sign;
	unsigned long	nb;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		if (nb > 9223372036854775)
		{
			if (sign == (unsigned long)-1)
				return (0);
			return (-1);
		}
		str++;
	}
	return ((int)(sign * nb));
}
