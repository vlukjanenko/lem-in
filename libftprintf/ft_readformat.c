/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:10:10 by majosue           #+#    #+#             */
/*   Updated: 2019/11/27 17:53:43 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_save_before_ptr(t_list **str, char **ptr, char **format)
{
	if (*ptr == *format)
		return (0);
	if (!(ft_lstp2back(str, *format, *ptr - *format)))
		return (-1);
	*format = *ptr;
	return (1);
}

int	ft_save_after_ptr(t_list **str, char **ptr, char **format)
{
	char *ftab[5];

	ft_gettab(&ftab, 5);
	(*ptr)++;
	if (!ft_chkflags(ptr, ftab))
	{
		*format = *ptr;
		return (1);
	}
	if (!(ft_lstp2back(str, *format, *ptr - *format)))
		return (-1);
	*format = *ptr;
	return (1);
}

int	ft_readformat(t_list **str, char *format)
{
	char *ptr;

	if (!*format)
		return (0);
	if ((ptr = ft_strchr(format, '%')))
	{
		if ((ft_save_before_ptr(str, &ptr, &format)) == -1)
			return (-1);
		if (ft_save_after_ptr(str, &ptr, &format) == -1)
			return (-1);
		return (ft_readformat(str, format));
	}
	if (!(ft_lstp2back(str, format, ft_strlen(format))))
		return (-1);
	return (1);
}
