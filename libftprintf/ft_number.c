/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:11:42 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 20:12:48 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Format string for 'd' or 'i' spec
*/

int			ft_number(t_list **str, va_list ap)
{
	char			*s;
	long long int	d;

	if (!(s = ft_strsub((*str)->content, 1, (*str)->content_size - 1)))
		return (0);
	free((*str)->content);
	ft_get_size(s, &d, ap);
	if (!((*str)->content = ft_itoa_base(d, 10)))
	{
		free(s);
		return (0);
	}
	(*str)->content_size = ft_strlen((*str)->content);
	if (!(ft_fmt_plus(str, s)) ||\
		!(ft_fmt_prec(str, s)) ||\
		!(ft_fmt_width(str, s)))
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}
