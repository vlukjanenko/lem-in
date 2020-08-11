/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:18:11 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 20:11:22 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Format string for 'u' specs
*/

#include "ft_printf.h"

int	ft_number_u(t_list **str, va_list ap)
{
	char					*s;
	unsigned long long int	d;

	if (!(s = ft_strsub((*str)->content, 1, (*str)->content_size - 1)))
		return (0);
	free((*str)->content);
	ft_get_size_u(s, &d, ap);
	if (!((*str)->content = ft_itoa_base_u(d, 10)))
	{
		free(s);
		return (0);
	}
	(*str)->content_size = ft_strlen((*str)->content);
	if (!(ft_fmt_prec(str, s)) ||
		!(ft_fmt_width(str, s)))
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}
