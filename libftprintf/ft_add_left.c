/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:36:09 by majosue           #+#    #+#             */
/*   Updated: 2019/11/28 10:42:24 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fill newstr with content at right & c at left
*/

void	ft_add_left(t_list **str, void **newstr, size_t w, char c)
{
	void *begin;

	begin = *newstr;
	ft_memset(*newstr, c, w - (*str)->content_size);
	*newstr += w - (*str)->content_size;
	ft_memcpy(*newstr, (*str)->content, (*str)->content_size);
	*newstr = begin;
}
