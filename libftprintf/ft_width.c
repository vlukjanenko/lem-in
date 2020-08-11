/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:18:44 by majosue           #+#    #+#             */
/*   Updated: 2019/11/29 12:22:15 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Set width  from format in w and return presence of it in format
*/

int	ft_width(char *str, size_t *w)
{
	int present;

	present = 0;
	ft_skipflags(&str);
	if (ft_isdigit(*str))
	{
		present = 1;
		*w = ft_atoi(str);
	}
	return (present);
}
