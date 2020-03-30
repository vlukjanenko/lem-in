/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:53:30 by majosue           #+#    #+#             */
/*   Updated: 2019/09/29 16:22:00 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*nstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if ((nstr = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	return (nstr);
}
