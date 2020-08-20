/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:13:16 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/31 16:15:02 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			get_height(const char *str, char c)
{
	size_t				height;

	height = 0;
	while (*str != '\0')
	{
		if (*str == c)
			height++;
		str++;
	}
	return (height + 1);
}

static const char		*ft_str_find_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

char					**ft_strsplit(char const *str, char c)
{
	char		**ret;
	int			i;
	const char	*next;

	if (str == NULL)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (get_height((char *)str, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, c, 1);
		if (*str != '\0')
		{
			next = ft_str_find_next(str, c, 0);
			ret[i] = ft_strsub(str, 0, next - str);
			if (ret[i] == NULL)
				return (ft_matrdel(&ret));
			i++;
			str = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
