/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:52:00 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 17:16:33 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Format digital string without leading signs (- + or space) and without # flag
*/

int	ft_fmt_width_d(t_list **str, char *s)
{
	size_t	w;
	size_t	p;
	void	*newstr;

	p = 0;
	w = (*str)->content_size;
	ft_width(s, &w);
	if (w <= (*str)->content_size)
		return (1);
	if (!(newstr = ft_memalloc(w)))
		return (0);
	if (ft_minus(s))
		ft_add_right(str, &newstr, w, ' ');
	else if ((ft_null(s) && !ft_prec(s, &p)) ||\
			(ft_null(s) && ft_strchr(s, 'f')))
		ft_add_left(str, &newstr, w, '0');
	else
		ft_add_left(str, &newstr, w, ' ');
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size = w;
	return (1);
}

/*
** Format digital string with leading signs (- + or space)
*/

int	ft_fmt_width_s(t_list **str, char *s)
{
	char	sign;
	size_t	p;
	size_t	size;
	void	*newstr;

	sign = ((char *)(*str)->content)[0];
	p = (*str)->content_size;
	ft_width(s, &p);
	if (p <= (*str)->content_size)
		return (1);
	((char *)(*str)->content)[0] = '0';
	size = p;
	if (!(newstr = ft_memalloc(size)))
		return (0);
	ft_add_left(str, &newstr, size, '0');
	((char *)newstr)[0] = sign;
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size = size;
	return (1);
}

/*
** Format digital string with leading 0x (# flag)
*/

int	ft_fmt_width_x(t_list **str, char *s)
{
	size_t	p;
	size_t	size;
	void	*newstr;

	p = (*str)->content_size;
	ft_width(s, &p);
	if (p <= (*str)->content_size)
		return (1);
	((char *)(*str)->content)[1] = '0';
	size = p;
	if (!(newstr = ft_memalloc(size)))
		return (0);
	ft_add_left(str, &newstr, size, '0');
	((char *)newstr)[1] = 'X';
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size = size;
	return (1);
}

/*
** Function chooser
*/

int	ft_fmt_width(t_list **str, char *s)
{
	size_t p;

	p = 0;
	if ((!ft_isalnum(((char *)(*str)->content)[0]) &&\
	ft_null(s) && !ft_prec(s, &p) && !ft_minus(s)) ||\
	(!ft_isalnum(((char *)(*str)->content)[0]) && ft_strchr(s, 'f') &&\
	ft_null(s) && !ft_minus(s)))
	{
		if (!(ft_fmt_width_s(str, s)))
			return (0);
	}
	else if (ft_strchr((char *)(*str)->content, 'X') &&\
	ft_null(s) && !ft_prec(s, &p) && !ft_minus(s))
	{
		if (!(ft_fmt_width_x(str, s)))
			return (0);
	}
	else
	{
		if (!(ft_fmt_width_d(str, s)))
			return (0);
	}
	return (1);
}
