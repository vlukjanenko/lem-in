/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:18:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 17:14:50 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				print_matrix(va_list arg)
{
	char			**matr;
	int				i;
	char			*number_of_str;

	if ((matr = va_arg(arg, char**)) == NULL)
		return ;
	i = 0;
	while (matr[i] != NULL)
	{
		ft_buffaddsymb(g_output, '[');
		number_of_str = ft_itoa(i);
		ft_buffadd(g_output, number_of_str);
		ft_strdel(&number_of_str);
		ft_buffladd(g_output, "] ", 2);
		ft_buffadd(g_output, matr[i++]);
		if (matr[i] != NULL)
			ft_buffaddsymb(g_output, '\n');
	}
}
