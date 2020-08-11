/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstp2back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:01:24 by majosue           #+#    #+#             */
/*   Updated: 2020/08/11 14:38:11 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lstp2back(t_list **begin_list, void const *content, size_t content_size)
{
	t_list *var1;

	var1 = *begin_list;
	if (var1 == 0)
	{
		*begin_list = ft_lstnew(content, content_size);
		if (!*begin_list)
			return (0);
	}
	else
	{
		while (var1->next != 0)
		{
			var1 = var1->next;
		}
		var1->next = ft_lstnew(content, content_size);
		if (!var1->next)
			return (0);
	}
	return (1);
}
