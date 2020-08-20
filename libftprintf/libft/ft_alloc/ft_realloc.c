/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:10:48 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:36:26 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"

void				*ft_realloc(void *ptr, size_t newsize)
{
	char			*new_ptr;

	if ((new_ptr = (char *)ft_memalloc(sizeof(char) * (newsize + 1))) == NULL)
		return (NULL);
	new_ptr = ft_strcpy(new_ptr, ptr);
	ft_memdel(&ptr);
	return (new_ptr);
}
