/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:30:44 by majosue           #+#    #+#             */
/*   Updated: 2019/09/16 14:49:50 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	if (!n)
		return (0);
	len = 0;
	while ((*s1 != '\0' || *s2 != '\0') && len < n)
	{
		if (*s1 != *s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
		len++;
	}
	return (0);
}
