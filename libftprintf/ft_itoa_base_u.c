/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:25:53 by majosue           #+#    #+#             */
/*   Updated: 2019/12/10 20:39:46 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		rn(unsigned long long value, int base)
{
	int rn;

	rn = 0;
	while (value > 0)
	{
		value = value / base;
		rn++;
	}
	if (rn == 0)
		return (1);
	return (rn);
}

char			*ft_itoa_base_u(unsigned long long int value, int base)
{
	char	*rezult;
	int		rezult_size;

	if (base < 2 || base > 16)
		return ((void *)0);
	rezult_size = rn(value, base);
	if (!(rezult = (char *)malloc(sizeof(char) * (rezult_size + 1))))
		return ((void *)0);
	rezult[rezult_size] = '\0';
	while ((rezult_size - 1) >= 0)
	{
		rezult[rezult_size - 1] = (value % base) >= 10 ?\
		value % base - 10 + 'A' : value % base + '0';
		value /= base;
		rezult_size--;
	}
	return (rezult);
}
