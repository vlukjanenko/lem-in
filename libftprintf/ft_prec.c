/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:29:15 by majosue           #+#    #+#             */
/*   Updated: 2019/11/29 12:31:38 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Set precision in p and return 1 if it exist
*/

int	ft_prec(char *str, size_t *p)
{
	char	*point;
	int		present;

	present = 0;
	if ((point = ft_strchr(str, '.')))
	{
		present = 1;
		*p = ft_atoi(point + 1);
	}
	return (present);
}
