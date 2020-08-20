/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dl_dll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:43:01 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/02 15:14:27 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_itoa_u(unsigned long long int n)
{
	long long int			len;
	char					*str;
	unsigned long long int	i;

	len = ft_numblen_u(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = len - 1;
	str[len] = '\0';
	while (n != 0)
	{
		str[i] = (n % 10) + 48;
		i--;
		n /= 10;
	}
	return (str);
}

static int	ft_itoa_help_u(unsigned long long int tmp, int base, int flag)
{
	int			size;

	size = 0;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	return (size);
}

static char	*ft_itoa_base_u(unsigned long long int value, int base)
{
	char				*str;
	int					size;
	int					flag;
	long long int		tmp;

	flag = 0;
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	size = ft_itoa_help_u(tmp, base, flag);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size > flag)
	{
		str[size - 1] = TAB[ft_abs(value % base)];
		size--;
		value /= base;
	}
	return (str);
}

int			display_u(unsigned long long int num, int base)
{
	char				*str;

	num = reduction_unsigned(num);
	if (num == 0 && g_spec->precision >= 0)
		str = ft_strnew(0);
	else if (g_spec->j == 1 || g_spec->symb == 'o' || g_spec->symb == 'x'
			|| g_spec->symb == 'X')
		str = ft_itoa_base_u(num, base);
	else
		str = ft_itoa_u(num);
	if (num > 9223372036854775807)
		num = 1;
	if (g_spec->symb == 'X' || g_spec->symb == 'x')
		str = register_x(str);
	width(num, str);
	print_width(num);
	if (num == 0 && g_spec->precision > 0)
		ft_buffadd(g_output, str);
	if (num > 0)
		ft_buffadd(g_output, str);
	if (num == 0 && g_spec->precision < 0)
		ft_buffadd(g_output, str);
	print_width_end();
	free(str);
	return (0);
}

void		print_u(va_list arg, int base)
{
	unsigned long long int	num;

	num = 0;
	if (g_spec->ll == 1)
		num = va_arg(arg, unsigned long long int);
	else if (g_spec->l == 1 || g_spec->symb == 'U')
		num = va_arg(arg, unsigned long);
	else if (g_spec->j == 1)
		num = va_arg(arg, size_t);
	else if (g_spec->z == 1)
		num = va_arg(arg, size_t);
	else if (g_spec->ll == 0 && g_spec->l == 0)
		num = va_arg(arg, unsigned int);
	display_u(num, base);
}
