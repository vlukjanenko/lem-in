/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:58:08 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 15:11:09 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long long int		reduction_signed(long long int num, unsigned long z)
{
	if (g_spec->l)
		num = (long int)num;
	else if (g_spec->l == 0 && g_spec->ll == 0 && g_spec->h == 0
			&& g_spec->hh == 0 && g_spec->j == 0 && g_spec->z == 0)
		num = (int)num;
	else if (g_spec->h == 1 && g_spec->z != 1 && g_spec->j != 1)
		num = (short)(num);
	else if (g_spec->hh == 1 && g_spec->z != 1 && g_spec->j != 1)
		num = (char)num;
	else if (g_spec->j == 1)
	{
		z = (unsigned long)num;
		return (z);
	}
	if (num < 0)
	{
		if ((g_spec->symb == 'x' || g_spec->symb == 'X' || g_spec->symb == 'o')
				&& g_spec->ll == 0)
			num += 4294967296;
		if ((g_spec->symb == 'x' || g_spec->symb == 'X' || g_spec->symb == 'o')
				&& g_spec->ll == 1)
			num += 1844674407370955161;
	}
	return (num);
}

unsigned long long	reduction_unsigned(unsigned long long int num)
{
	if (g_spec->l == 1)
		num = (unsigned long int)num;
	else if (g_spec->symb == 'U')
		num = (unsigned long)num;
	else if (g_spec->ll == 0 && g_spec->l == 0 && g_spec->j == 0
		&& g_spec->h == 0 && g_spec->hh == 0 && g_spec->z == 0)
		num = (unsigned int)num;
	else if (g_spec->h == 1)
		num = (unsigned short)num;
	else if (g_spec->hh == 1)
		num = (unsigned char)num;
	else if (g_spec->z == 1)
		num = (size_t)num;
	return (num);
}

int					ft_numblen_u(unsigned long long int n)
{
	int			i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int					lenbase(unsigned long long int num)
{
	int			size;

	size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	if (size == 0)
		return (1);
	return (size);
}

void				assembl_int(va_list arg, int base)
{
	long long int	check;

	check = 0;
	if (g_spec->symb == 'x' || g_spec->symb == 'X')
		base = 16;
	if (g_spec->symb == 'o')
		base = 8;
	if (g_spec->symb == 'u' || g_spec->symb == 'U' || g_spec->symb == 'o'
			|| g_spec->symb == 'x' || g_spec->symb == 'X')
	{
		print_u(arg, base);
		return ;
	}
	if (g_spec->l == 1)
		check = va_arg(arg, long int);
	else if (g_spec->ll == 1)
		check = va_arg(arg, long long int);
	else if (g_spec->l == 0 && g_spec->ll == 0 && g_spec->j == 0
			&& g_spec->z == 0)
		check = va_arg(arg, int);
	else if (g_spec->z == 1)
		check = va_arg(arg, size_t);
	else if (g_spec->j == 1)
		check = va_arg(arg, size_t);
	display_int(check, base);
}
