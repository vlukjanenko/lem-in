/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 07:12:47 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 20:57:34 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len > 0)
		{
			((unsigned char*)dst)[len - 1] = ((unsigned char*)src)[len - 1];
			len--;
		}
	return (dst);
}
