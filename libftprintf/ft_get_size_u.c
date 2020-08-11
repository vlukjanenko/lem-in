/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:03:21 by majosue           #+#    #+#             */
/*   Updated: 2019/12/10 18:29:35 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Put in 'd' argument appropriate unsigned size
*/

void	ft_get_size_u_part2(char *str, unsigned long long int *d, va_list ap)
{
	t_type_u tmp;

	if (str[0] == 'h' && str[1] != 'h')
	{
		tmp.si = va_arg(ap, unsigned int);
		*d = tmp.si;
	}
	if (str[0] == 'l' && str[1] != 'l')
	{
		tmp.li = va_arg(ap, unsigned long int);
		*d = tmp.li;
	}
	if (str[0] != 'l' && str[0] != 'h' && str[0] != 'L')
	{
		tmp.i = va_arg(ap, unsigned int);
		*d = tmp.i;
	}
}

void	ft_get_size_u(char *str, unsigned long long int *d, va_list ap)
{
	char		*s[5];
	t_type_u	tmp;

	ft_gettab(&s, 5);
	s[3] = "";
	s[4] = "";
	ft_chkflags(&str, s);
	if (str[0] == 'l' && str[1] == 'l')
	{
		tmp.lli = va_arg(ap, unsigned long long int);
		*d = tmp.lli;
	}
	if (str[0] == 'h' && str[1] == 'h')
	{
		tmp.c = va_arg(ap, unsigned int);
		*d = tmp.c;
	}
	ft_get_size_u_part2(str, d, ap);
}
