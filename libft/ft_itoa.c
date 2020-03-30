/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:22:31 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 21:37:00 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dnbr(unsigned int nbr)
{
	int dnbr;

	dnbr = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		dnbr++;
	}
	if (!dnbr)
		return (1);
	return (dnbr);
}

char			*ft_itoa(int n)
{
	int				sign;
	char			*str;
	int				size;
	unsigned int	nbr;

	sign = 0;
	if (n < 0)
		sign = 1;
	nbr = n >= 0 ? n : -n;
	size = ft_dnbr(nbr) + sign;
	if ((str = ft_strnew(size)) == NULL)
		return (NULL);
	if (n == 0)
		*str = '0';
	if (sign == 1)
		*str = '-';
	size--;
	while (size >= sign)
	{
		str[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
