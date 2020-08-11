/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:02:55 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 20:09:00 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(t_list **str, va_list ap)
{
	char	*s;
	char	*s1;
	size_t	p;

	if (!(s = ft_strsub((*str)->content, 1, (*str)->content_size - 1)))
		return (0);
	free((*str)->content);
	if (!(s1 = (va_arg(ap, char *))))
		s1 = "(null)";
	p = ft_strlen(s1);
	ft_prec(s, &p);
	p = p > ft_strlen(s1) ? ft_strlen(s1) : p;
	(*str)->content_size = p;
	if (((*str)->content = ft_strsub(s1, 0, p)) && ft_fmt_char(str, s))
	{
		free(s);
		return (1);
	}
	free(s);
	return (0);
}
