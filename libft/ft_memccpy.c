/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:41:39 by majosue           #+#    #+#             */
/*   Updated: 2019/09/13 16:25:08 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (*(unsigned char*)src == (unsigned char)c)
			return (++dst);
		i++;
		dst++;
		src++;
	}
	return (NULL);
}
