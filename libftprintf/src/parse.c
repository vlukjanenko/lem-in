/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:44:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 14:47:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void				nullify_llhh_bigl(int flag)
{
	g_spec->l = 0;
	g_spec->h = 0;
	g_spec->ll = 0;
	g_spec->hh = 0;
	g_spec->big_l = 0;
	if (flag == 1)
		g_spec->l = 1;
	else if (flag == 2)
		g_spec->ll = 1;
	else if (flag == 3)
		g_spec->big_l = 1;
	else if (flag == 4)
		g_spec->h = 1;
	else if (flag == 5)
		g_spec->hh = 1;
}

char					*parse_lh_bigl(char *traverse)
{
	if (*traverse == 'L' && g_spec->symb != 'd')
	{
		nullify_llhh_bigl(3);
		traverse++;
		return (traverse);
	}
	if (*(traverse + 1) == *traverse)
	{
		if (*traverse == 'l')
			nullify_llhh_bigl(2);
		else if (*traverse == 'h')
			nullify_llhh_bigl(5);
	}
	else
	{
		if (*traverse == 'l')
			nullify_llhh_bigl(1);
		else if (*traverse == 'h')
			nullify_llhh_bigl(4);
	}
	if (g_spec->big_l == 1 || g_spec->l == 1 || g_spec->h == 1)
		traverse++;
	else if (g_spec->ll == 1 || g_spec->hh == 1)
		traverse += 2;
	return (parsesymb(traverse));
}

char					*parse_calculatesymb(char *traverse)
{
	if (*traverse == '#')
	{
		g_spec->sharp = 1;
		traverse++;
	}
	else if (*traverse == '0')
	{
		g_spec->zero = 1;
		traverse++;
	}
	else if (*traverse == '+')
	{
		g_spec->plus = 1;
		traverse++;
	}
	else if (*traverse == '-')
	{
		g_spec->minus = 1;
		traverse++;
	}
	return (parsesymb(traverse));
}

char					*parse_digit(char *traverse, const int flag)
{
	int		num;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_isdigit(*traverse) != 1)
		return (traverse);
	while (ft_isdigit(traverse[j]) == 1)
	{
		i++;
		j++;
	}
	str = (char *)ft_memalloc(sizeof(char) * (i + 1));
	str = ft_strncpy(str, traverse, i);
	num = ft_atoi(str);
	if (flag == WIDTH)
		g_spec->width = num;
	else if (flag == PRECISION)
		g_spec->precision = num;
	ft_strdel(&str);
	return (traverse + i);
}

char					*parse_width_or_precision(char *traverse, int flag)
{
	if (flag == PRECISION)
	{
		g_spec->precision = 0;
		traverse = parse_digit(++traverse, flag);
	}
	else if (flag == WIDTH)
		traverse = parse_digit(traverse, flag);
	return (parsesymb(traverse));
}
