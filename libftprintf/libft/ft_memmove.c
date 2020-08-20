/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:38:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			i;

	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (str_dst == str_src)
		return (str_dst);
	if (str_dst < str_src)
	{
		i = -1;
		while (++i < len)
			str_dst[i] = str_src[i];
	}
	else
	{
		i = len - 1;
		while (i + 1)
		{
			str_dst[i] = str_src[i];
			i--;
		}
	}
	return (str_dst);
}
