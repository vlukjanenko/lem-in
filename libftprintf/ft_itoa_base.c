/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:25:53 by majosue           #+#    #+#             */
/*   Updated: 2019/12/10 20:39:04 by majosue          ###   ########.fr       */
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

char			*ft_itoa_base(long long int value, int base)
{
	unsigned long long int	uvalue;
	char					*rezult;
	int						rezult_size;
	int						sign;

	if (base < 2 || base > 16)
		return ((void *)0);
	sign = value < 0 && base == 10 ? 1 : 0;
	uvalue = value < 0 ? -value : value;
	rezult_size = rn(uvalue, base);
	rezult_size += sign;
	if (!(rezult = (char *)malloc(sizeof(char) * (rezult_size + 1))))
		return ((void *)0);
	rezult[rezult_size] = '\0';
	if (sign)
		rezult[0] = '-';
	while ((rezult_size - 1) >= sign)
	{
		rezult[rezult_size - 1] = (uvalue % base) >= 10 ?\
		uvalue % base - 10 + 'A' : uvalue % base + '0';
		uvalue /= base;
		rezult_size--;
	}
	return (rezult);
}
