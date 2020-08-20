/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 12:33:27 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 17:39:00 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_without_spaces(char *s)
{
	int		i;
	int		wts;
	int		start;

	i = 0;
	wts = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (0);
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i--;
	while (i-- >= start)
		wts++;
	return (wts);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		end;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_without_spaces((char *)s) + 1));
	if (!str)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i--;
	if (i == 0)
		return (NULL);
	end = i;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	while (i <= end)
		str[j++] = s[i++];
	str[j++] = '\0';
	return (str);
}
