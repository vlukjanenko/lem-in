/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:47:35 by majosue           #+#    #+#             */
/*   Updated: 2019/09/16 08:07:07 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			tmp = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (tmp);
}
