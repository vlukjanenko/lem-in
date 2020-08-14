/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstp2back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:01:24 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 08:10:01 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstp2back(t_list **begin_list,\
void const *content, size_t content_size)
{
	t_list *var1;

	var1 = *begin_list;
	if (var1 == 0)
	{
		return (*begin_list = ft_lstnew(content, content_size));
	}
	while (var1->next != 0)
	{
		var1 = var1->next;
	}
	var1->next = ft_lstnew(content, content_size);
	return (var1->next);
}
