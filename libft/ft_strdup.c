/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:47:06 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 20:59:01 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if ((s2 = ft_strnew(ft_strlen(s1))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
