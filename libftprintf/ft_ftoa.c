/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:42:20 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 15:57:07 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_combain(char *entire, char *bufer, char *sign, int p)
{
	size_t	len;
	char	*res;

	len = ft_strlen(sign) + ft_strlen(entire) + p;
	len = p > 0 ? len + 1 : len;
	if (!(res = ft_strnew(len)))
		return (0);
	ft_strcat(res, sign);
	ft_strcat(res, entire);
	if (p > 0)
	{
		ft_strcat(res, ".");
		ft_strcat(res, bufer);
		ft_memset(res + len - (p - ft_strlen(bufer)),\
		'0', p - ft_strlen(bufer));
	}
	return (res);
}

void	ft_to_string(char (*bufer)[70], int n)
{
	int i;

	n > 70 ? n = 70 : n;
	i = 0;
	while (i < n)
	{
		(*bufer)[i] = (*bufer)[i] + '0';
		i++;
	}
}

int		ft_round(char (*bufer)[70], int p)
{
	int hd;

	hd = (*bufer)[p] < 5 ? 0 : 1;
	(*bufer)[p] = 0;
	while (hd == 1 && p > 0)
	{
		hd = ((*bufer)[p - 1] + 1) / 10;
		(*bufer)[p - 1] = ((*bufer)[p - 1] + 1) % 10;
		p--;
	}
	return (hd);
}

int		ft_fract(char (*bufer)[70], long double n, int p)
{
	int					i;
	int					hd;
	unsigned long long	tmp;
	long double			m;

	m = n;
	hd = 0;
	i = 0;
	tmp = 10;
	while (n > 0 && i < 70)
	{
		n = 10 * n;
		(*bufer)[i] = i < 19 ? (unsigned long long)(m * tmp) % 10 : (char)(n);
		i < 19 ? tmp *= 10 : i;
		n = (n - (char)n);
		i++;
	}
	if (i > p)
	{
		hd = ft_round(bufer, p);
		ft_to_string(bufer, p);
	}
	else
		ft_to_string(bufer, i);
	return (hd);
}

char	*ft_ftoa(long double n, int p)
{
	char	*sign;
	char	*entire;
	char	*rezult;
	char	bufer[70];
	int		hd;

	sign = n < 0 ? "-" : "";
	n = n < 0 ? -n : n;
	ft_bzero(bufer, 70);
	hd = ft_fract(&bufer, n - (long int)n, p);
	if (!(entire = ft_itoa_base((long int)n + hd, 10)))
		return (0);
	if (!(rezult = ft_str_combain(entire, bufer, sign, p)))
		return (0);
	free(entire);
	return (rezult);
}
