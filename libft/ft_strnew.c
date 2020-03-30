/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:48:08 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 20:59:42 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == 18446744073709551615U)
		return (NULL);
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
