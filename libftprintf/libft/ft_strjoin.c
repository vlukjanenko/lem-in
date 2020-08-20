/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:19:30 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:51 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	length1;
	size_t	length2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (length1 + length2 + 1));
	if (!str)
		return (NULL);
	while (i < length1)
		str[j++] = s1[i++];
	i = 0;
	while (i < length2)
		str[j++] = s2[i++];
	str[j++] = '\0';
	return (str);
}
