/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 19:49:11 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/01 19:59:27 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		ft_round_sen(char *result, int size_result, int *transfer)
{
	if (result[size_result] + *transfer > 57
		&& result[size_result] != 46)
	{
		result[size_result] = 48;
		*transfer = 1;
	}
	else if (result[size_result] >= 48 && result[size_result] <= 57)
	{
		result[size_result] = result[size_result] + *transfer;
		*transfer = 0;
	}
	if (result[size_result] == 46 && g_spec->precision < 0)
		result[size_result] = '\0';
}

void			ft_rounding(char *result, int size_result, t_part *part)
{
	int				index;
	int				transfer;

	transfer = 0;
	index = 0;
	if (result[size_result - 2] >= 53 || (result[size_result - 2] == 53
			&& result[size_result - 1] >= 54))
		transfer = 1;
	result[size_result - 2] = '\0';
	size_result -= 3;
	while (size_result >= 0)
	{
		if (transfer == 1)
			ft_round_sen(result, size_result, &transfer);
		size_result--;
	}
	if (transfer == 1)
		ft_buffadd(part->middle, "1");
	if (g_spec->sharp == 1)
		ft_buffadd(part->middle, ".");
}
