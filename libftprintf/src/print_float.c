/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:32:41 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 19:23:20 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void			getnumber(t_part *part, long double num)
{
	unsigned long long		number;
	int						i;
	char					str[2];
	char					*tmp;

	str[1] = '\0';
	i = 0;
	number = (unsigned long long)num;
	num -= number;
	tmp = ft_itoa_u(number);
	ft_buffadd(part->middle, tmp);
	ft_strdel(&tmp);
	if (g_spec->precision != 0 || g_spec->sharp == 1)
		ft_buffadd(part->middle, ".");
	while (i < g_spec->precision + 3)
	{
		number = (double)num * 10;
		num *= 10;
		num -= number;
		str[0] = number + 48;
		ft_buffadd(part->middle, str);
		i++;
	}
}

void			fill_parts_float(t_part *part, long double num)
{
	getnumber(part, num);
	ft_rounding(part->middle->str, part->middle->i - 1, part);
	getfirst(part, part->middle->i);
	getend(part);
	ft_buffadd(g_output, part->first);
	ft_buffadd(g_output, part->middle->str);
	ft_buffadd(g_output, part->last);
	partdel(&part);
}

void			print_float(va_list arg)
{
	long double		num;
	t_part			*part;
	t_lnum			bit;

	part = init_part();
	part->middle = ft_buffinit(10);
	if (g_spec->precision == -1)
		g_spec->precision = 6;
	if (g_spec->big_l == 0)
		num = va_arg(arg, double);
	else
		num = va_arg(arg, long double);
	bit.f = num;
	if (bit.t_bitfloat.sign == 1)
	{
		num *= -1;
		part->is_neg = 1;
	}
	fill_parts_float(part, num);
}
