/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:48:32 by majosue           #+#    #+#             */
/*   Updated: 2019/09/29 12:08:40 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = dst;
	i = 0;
	while (i < len)
	{
		*dst = *src;
		if (*src != '\0')
			src++;
		dst++;
		i++;
	}
	return (ptr);
}
