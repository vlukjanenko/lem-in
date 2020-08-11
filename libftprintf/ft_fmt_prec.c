/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:37:59 by majosue           #+#    #+#             */
/*   Updated: 2019/12/11 11:31:55 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fmt_prec_x(t_list **str, char *s)
{
	size_t	p;
	size_t	size;
	void	*newstr;
	int		presist;

	p = (*str)->content_size - 2;
	presist = ft_prec(s, &p);
	if (presist && !p && ((char *)(*str)->content)[2] == '0')
	{
		(*str)->content_size--;
		return (1);
	}
	if (p <= (*str)->content_size - 2)
		return (1);
	((char *)(*str)->content)[1] = '0';
	size = p + 2;
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
** Format presision string with leading symbols + - space
*/

int	ft_fmt_prec_s(t_list **str, char *s)
{
	char	sign;
	size_t	p;
	size_t	size;
	void	*newstr;

	sign = ((char *)(*str)->content)[0];
	p = (*str)->content_size - 1;
	if (ft_prec(s, &p) && !p && ((char *)(*str)->content)[1] == '0')
	{
		(*str)->content_size--;
		return (1);
	}
	if (p <= (*str)->content_size - 1)
		return (1);
	((char *)(*str)->content)[0] = '0';
	size = p + 1;
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
** Format precision in digital string without leading signs (- + or space)
*/

int	ft_fmt_prec_d(t_list **str, char *s)
{
	size_t	p;
	int		presist;
	void	*newstr;

	p = (*str)->content_size;
	presist = ft_prec(s, &p);
	if (presist && !p && ((char *)(*str)->content)[0] == '0')
	{
		(*str)->content_size = ft_strchr(s, '#') && ft_strchr(s, 'o') ?\
		(*str)->content_size : (*str)->content_size - 1;
		return (1);
	}
	if (p <= (*str)->content_size)
		return (1);
	if (!(newstr = ft_memalloc(p)))
		return (0);
	ft_add_left(str, &newstr, p, '0');
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size = p;
	return (1);
}

/*
** Function chooser
*/

int	ft_fmt_prec(t_list **str, char *s)
{
	if (ft_isalnum(((char *)(*str)->content)[0]) &&\
	!ft_strchr((char *)(*str)->content, 'X'))
	{
		if (!(ft_fmt_prec_d(str, s)))
			return (0);
	}
	else if (ft_strchr((char *)(*str)->content, 'X'))
	{
		if (!(ft_fmt_prec_x(str, s)))
			return (0);
	}
	else
	{
		if (!(ft_fmt_prec_s(str, s)))
			return (0);
	}
	return (1);
}
