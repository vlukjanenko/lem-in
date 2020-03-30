/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:16:44 by majosue           #+#    #+#             */
/*   Updated: 2019/09/29 09:50:56 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nl;
	size_t i;

	nl = ft_strlen(needle);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	i = 0;
	while ((i + nl) <= len)
	{
		if (ft_strncmp(needle, haystack, nl) == 0)
			return ((char*)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
