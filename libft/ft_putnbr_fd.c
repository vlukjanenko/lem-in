/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:59:49 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 21:36:15 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putabs(int n, int fd)
{
	unsigned int nbr;

	nbr = n >= 0 ? n : -n;
	if (nbr != 0)
	{
		ft_putabs(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putabs(n, fd);
	}
	else
		ft_putabs(n, fd);
}
