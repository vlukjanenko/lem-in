/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 09:31:52 by majosue           #+#    #+#             */
/*   Updated: 2019/09/29 11:49:49 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlend(const char *str, char c)
{
	size_t len;

	len = 0;
	while (*str != c && *str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

static size_t	ft_wrdnbr(char const *s, char c)
{
	size_t n;

	n = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			n++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (n);
}

static void		*ft_cleanup(char **m, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		ft_strdel(&m[i++]);
	free(m);
	m = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	len;
	size_t	strlen;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_wrdnbr(s, c);
	result = (char**)malloc(sizeof(char*) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		while (*s == c)
			s++;
		strlen = ft_strlend(s, c);
		if ((result[i] = ft_strsub(s, 0, strlen)) == NULL)
			return (ft_cleanup(result, i));
		s += strlen;
		i++;
	}
	result[len] = NULL;
	return (result);
}
