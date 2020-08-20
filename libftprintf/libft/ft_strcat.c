/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:25:36 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:44 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str, const char *tail)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str);
	while (tail[i] != '\0')
	{
		str[j] = tail[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
