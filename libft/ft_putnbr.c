/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:59:49 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 21:37:03 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putabs(int n)
{
	unsigned int nbr;

	nbr = n >= 0 ? n : -n;
	if (nbr != 0)
	{
		ft_putabs(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putabs(n);
	}
	else
		ft_putabs(n);
}
