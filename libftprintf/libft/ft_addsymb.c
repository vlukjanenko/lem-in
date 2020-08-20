/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsymb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:06:02 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:31 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_addsymb(char *str, char c, int num)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	i = 0;
	j = 0;
	if (num < 0)
		return (NULL);
	len = ft_strlen(str) + num;
	newstr = (char *)ft_memalloc(sizeof(char) * len);
	while (i < num)
	{
		newstr[i] = c;
		i++;
	}
	while (str[j] != '\0')
	{
		newstr[i] = str[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	ft_strdel(&str);
	return (newstr);
}
