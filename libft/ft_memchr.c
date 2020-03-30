/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 08:05:13 by majosue           #+#    #+#             */
/*   Updated: 2019/09/13 16:32:27 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)s == (unsigned char)c)
			return ((void*)s);
		i++;
		s++;
	}
	return (NULL);
}
