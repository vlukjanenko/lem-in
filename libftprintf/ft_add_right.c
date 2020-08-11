/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:42:52 by majosue           #+#    #+#             */
/*   Updated: 2019/11/28 10:44:04 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fill newstr with content at left & c at right
*/

void	ft_add_right(t_list **str, void **newstr, size_t w, char c)
{
	void *begin;

	begin = *newstr;
	ft_memcpy(*newstr, (*str)->content, (*str)->content_size);
	*newstr += (*str)->content_size;
	ft_memset(*newstr, c, w - (*str)->content_size);
	*newstr = begin;
}
