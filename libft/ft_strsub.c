/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:35:31 by majosue           #+#    #+#             */
/*   Updated: 2019/09/30 11:59:39 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sstr;

	if (!s)
		return (NULL);
	if ((sstr = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strncpy(sstr, s + start, len);
	return (sstr);
}
