/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:44:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = ft_strlen(s2);
	if (length == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		while (s2[j] == s1[i + j])
		{
			if (j == length - 1)
				return ((char *)(s1 + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
