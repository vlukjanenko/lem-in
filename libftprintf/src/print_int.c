/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:44:01 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/02 16:12:19 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		width_three(long long num, char *str)
{
	if (g_spec->symb == 'o')
	{
		if (num >= 0 && g_spec->precision <= g_width->width)
		{
			if (str[0] == '0')
				return ;
			g_width->space_right -= 1;
			g_width->space_left -= 1;
		}
	}
	if (g_spec->precision == 0 && str[0] == '0' && g_spec->symb == 'p')
	{
		g_width->space_left -= 1;
		g_width->zero -= 1;
		g_width->space_right -= 1;
	}
	else if (g_spec->symb == 'p')
	{
		g_width->space_left -= 2;
		if (g_spec->precision < 0)
			g_width->zero -= 2;
		g_width->space_right -= 2;
	}
}

static void		width_two(long long int num, char *str)
{
	if (g_spec->zero == 1 && g_spec->precision < 0)
	{
		if (g_spec->symb != 'p')
			g_width->zero = g_width->space_left;
		else if (g_spec->symb == 'p' && g_spec->precision == -1)
			g_width->zero = g_width->space_left;
		if (g_spec->sharp == 1 && (g_spec->symb == 'x' || g_spec->symb == 'X')
			&& num != 0)
			g_width->zero -= 2;
		g_width->space_left = 0;
	}
	if (g_spec->space == 1 && num >= 0 && g_spec->symb != 'u'
		&& g_spec->symb != 'c' && g_spec->symb != 'U' && g_spec->symb
		!= 's' && g_spec->symb != 'o' && g_spec->symb != 'p')
		width_four();
	if ((g_spec->sharp == 1 && g_spec->width > 0) || g_spec->symb == 'p')
	{
		if ((g_spec->symb == 'x' || g_spec->symb == 'X') && num > 0)
		{
			g_width->space_left -= 2;
			g_width->space_right -= 2;
		}
		width_three(num, str);
	}
}

void			width(long long int number, char *str)
{
	long long int	num;

	num = number;
	g_width->width = ft_strlen(str);
	number = (g_spec->precision - g_width->width);
	if (num < 0)
		g_width->width++;
	if (number < 0)
		number = 0;
	if (g_spec->width > g_width->width && g_spec->minus == 0)
		g_width->space_left = g_spec->width - g_width->width;
	else if (g_spec->minus == 1 && (g_spec->width > g_spec->precision
			|| g_spec->symb == 's'))
		g_width->space_right = g_spec->width - g_width->width;
	if (number != 0 && g_spec->symb != 's')
	{
		g_width->zero = number;
		g_width->space_left -= number;
		g_width->space_right -= number;
	}
	width_two(num, str);
	return ;
}

static void		print_widthtwo(long long int num)
{
	int			index;

	index = 0;
	if (g_width->space_left > 0)
	{
		if (g_spec->plus == 1 && num >= 0 && g_spec->symb != 'o'
		&& g_spec->symb != 'c' && g_spec->symb != 'p' && g_spec->symb != 'u'
		&& g_spec->symb != 's' && g_spec->symb != 'f')
			g_width->space_left = g_width->space_left - 1;
		while (index < g_width->space_left)
		{
			ft_buffaddsymb(g_output, ' ');
			index++;
		}
		sign(num);
		return ;
	}
	if (g_spec->symb != 'x' && g_spec->symb != 'X' && g_spec->symb != 'p')
		sign(num);
	if (g_spec->symb == 'x' || g_spec->symb == 'X' || g_spec->symb == 'p')
		sign_x(num);
}

void			print_width(long long int num)
{
	if (g_spec->symb == 's' && g_width->width == 0 && g_spec->zero == 0)
	{
		g_width->space_left = g_spec->width;
		g_width->space_right = 0;
	}
	if (g_spec->symb == 'c' && g_width->width == 1)
	{
		if (g_spec->zero == 0 && g_spec->minus == 0)
		{
			g_width->zero = 0;
			g_width->space_left = g_spec->width - g_width->width;
		}
		else if (g_spec->zero == 0 && g_spec->minus == 1)
		{
			g_width->zero = 0;
			g_width->space_left = 0;
			g_width->space_right = g_spec->width - g_width->width;
		}
	}
	print_widthtwo(num);
	if (g_width->zero > 0)
		while (g_width->zero-- > 0)
			ft_buffaddsymb(g_output, '0');
	return ;
}
