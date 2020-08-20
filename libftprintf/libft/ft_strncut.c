/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:23:29 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:38:55 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*first(char *str, int n)
{
	char	*segment;
	int		i;

	i = 0;
	segment = (char *)ft_memalloc(n + 1);
	while (i < n)
	{
		segment[i] = str[i];
		i++;
	}
	segment[i] = '\0';
	return (segment);
}

static char		*second(char *str, int n)
{
	char	*segment;
	int		i;
	int		j;

	i = n;
	j = 0;
	segment = (char *)ft_memalloc(ft_strlen(str + n));
	while (str[i] != '\0')
	{
		segment[j] = str[i];
		i++;
		j++;
	}
	segment[j] = '\0';
	return (segment);
}

char			*ft_strncut(char *str, int n, char *choice)
{
	if (str == NULL)
		return (NULL);
	if ((int)ft_strlen(str) < n || n < 0)
		return (NULL);
	if ((int)ft_strlen(str) == n)
		return (str);
	if (ft_strcmp(choice, "first") == 0)
		return (first(str, n));
	else if (ft_strcmp(choice, "second") == 0)
		return (second(str, n));
	return (NULL);
}
