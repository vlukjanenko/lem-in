/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:09:47 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 20:10:39 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Handling # flag
*/

int		ft_fmt_sharp_x(t_list **str, char *s)
{
	void *newstr;

	if ((((char *)(*str)->content)[0] == '0' ||\
	!ft_sharp(s)) && !ft_strchr(s, 'p'))
		return (1);
	if (!(newstr = ft_strjoin("0X", (char *)(*str)->content)))
		return (0);
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size += 2;
	return (1);
}

/*
** Handling lowcase x
*/

void	ft_fmt_lowc(t_list **str)
{
	size_t i;

	i = 0;
	while (i < (*str)->content_size)
	{
		if (((char *)(*str)->content)[i] >= 'A' &&\
		((char *)(*str)->content)[i] <= 'X')
			((char *)(*str)->content)[i] = ((char *)(*str)->content)[i] + 32;
		i++;
	}
}

/*
** Format string for 'x' 'X' specs
*/

int		ft_number_x(t_list **str, va_list ap)
{
	char					*s;
	unsigned long long int	d;

	if (!(s = ft_strsub((*str)->content, 1, (*str)->content_size - 1)))
		return (0);
	free((*str)->content);
	ft_strchr(s, 'p') ? d = va_arg(ap, long int) : ft_get_size_u(s, &d, ap);
	if (!((*str)->content = ft_itoa_base_u(d, 16)))
	{
		free(s);
		return (0);
	}
	(*str)->content_size = ft_strlen((*str)->content);
	if (!(ft_fmt_sharp_x(str, s)) ||
		!(ft_fmt_prec(str, s)) ||
		!(ft_fmt_width(str, s)))
	{
		free(s);
		return (0);
	}
	ft_strchr(s, 'x') || ft_strchr(s, 'p') ? ft_fmt_lowc(str) : s;
	free(s);
	return (1);
}
