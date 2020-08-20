/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:17:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:53 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnadd(char *str, char c, size_t n)
{
	int i;

	if (str == NULL)
		return (NULL);
	i = n;
	str[i] = c;
	return (str);
}
