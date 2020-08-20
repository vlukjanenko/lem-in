/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:29:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:39 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	size_t			i;

	i = 0;
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	if (str_dst == str_src)
		return (str_dst);
	while (i < n)
	{
		if (str_src[i] == '\0')
			str_dst[i] = '\0';
		str_dst[i] = str_src[i];
		i++;
	}
	return (str_dst);
}
