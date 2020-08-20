/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:39:37 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/02 12:41:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_itoa_help(long long int tmp, int base, int flag)
{
	int					size;

	size = 0;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	return (size);
}

static int	ft_itoa_unhelp(unsigned long long tmp, int base, int flag)
{
	int					size;

	size = 0;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	return (size);
}

char		*ft_itoa_unbase(unsigned long long value, int base)
{
	int					size;
	int					flag;
	unsigned long long	tmp;
	char				*str;

	flag = 0;
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	size = ft_itoa_unhelp(tmp, base, flag);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size > flag)
	{
		str[size - 1] = TAB[value % base];
		size--;
		value /= base;
	}
	return (str);
}

char		*ft_itoa_base(long long int value, int base)
{
	char			*str;
	int				size;
	int				flag;
	long long int	tmp;

	flag = 0;
	if (value < -9223372036854775807)
		return (ft_strcpy(ft_strnew(21), "9223372036854775808"));
	if (g_spec->symb == 'p' && value < 0)
		return (ft_itoa_unbase(value, base));
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	size = ft_itoa_help(tmp, base, flag);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size > flag)
	{
		str[size-- - 1] = TAB[ft_abs(value % base)];
		value /= base;
	}
	return (str);
}
