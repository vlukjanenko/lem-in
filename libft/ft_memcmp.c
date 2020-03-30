/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 08:35:06 by majosue           #+#    #+#             */
/*   Updated: 2019/09/13 16:33:16 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char*)s1 - *(unsigned char*)s2) != 0)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
