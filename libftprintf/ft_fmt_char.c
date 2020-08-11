/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:51:55 by majosue           #+#    #+#             */
/*   Updated: 2019/11/29 12:52:59 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Preformat output for char string
** char or %
*/

int	ft_fmt_char(t_list **str, char *s)
{
	size_t	w;
	void	*newstr;

	w = (*str)->content_size;
	ft_width(s, &w);
	if (w <= (*str)->content_size)
		return (1);
	if (!(newstr = ft_memalloc(w)))
		return (0);
	if (ft_minus(s))
		ft_add_right(str, &newstr, w, ' ');
	else if (ft_null(s))
		ft_add_left(str, &newstr, w, '0');
	else
		ft_add_left(str, &newstr, w, ' ');
	free((*str)->content);
	(*str)->content = newstr;
	(*str)->content_size = w;
	return (1);
}
