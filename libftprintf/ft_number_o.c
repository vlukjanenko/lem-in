/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:59:42 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 20:11:50 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Handling # flag
*/

int	ft_fmt_sharp_o(t_list **str, char *s)
{
	void *newstr;

	if (!ft_sharp(s) || ((char *)(*str)->content)[0] == '0')
		return (1);
	if (!(newstr = ft_strjoin("0", (char *)(*str)->content)))
		return (0);
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size += 1;
	return (1);
}

/*
** Format string for 'o' spec
*/

int	ft_number_o(t_list **str, va_list ap)
{
	char					*s;
	unsigned long long int	d;

	if (!(s = ft_strsub((*str)->content, 1, (*str)->content_size - 1)))
		return (0);
	free((*str)->content);
	ft_get_size_u(s, &d, ap);
	if (!((*str)->content = ft_itoa_base_u(d, 8)))
	{
		free(s);
		return (0);
	}
	(*str)->content_size = ft_strlen((*str)->content);
	if (!(ft_fmt_sharp_o(str, s)) ||
		!(ft_fmt_prec(str, s)) ||
		!(ft_fmt_width(str, s)))
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}
