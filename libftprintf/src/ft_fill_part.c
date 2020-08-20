/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 20:08:03 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/02 18:14:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void		getfirst_min(t_part *part, int *i, int size_zero)
{
	if (g_spec->minus == 0)
	{
		if (g_spec->zero)
		{
			if (g_spec->plus && !(part->is_neg))
				part->first[(*i)++] = '+';
			if (part->is_neg)
				part->first[(*i)++] = '-';
			while (*i < size_zero)
				part->first[(*i)++] = '0';
		}
		else
		{
			if ((g_spec->plus && !(part->is_neg)) || (part->is_neg))
				size_zero--;
			while (*i < size_zero)
				part->first[(*i)++] = ' ';
			if (g_spec->plus && !(part->is_neg))
				part->first[(*i)++] = '+';
			if (part->is_neg)
				part->first[(*i)++] = '-';
		}
	}
}

void			getfirst(t_part *part, int size_middle)
{
	int			size_zero;
	int			i;

	i = 0;
	size_zero = g_spec->width - size_middle;
	if (size_zero <= 0)
		part->first = ft_strnew(1);
	else
		part->first = ft_strnew(size_zero + 1);
	if ((size_zero <= 0 || (size_zero && g_spec->zero) || g_spec->minus == 1)
		&& !(g_spec->plus) && !(part->is_neg) && g_spec->space == 1)
		part->first[i++] = ' ';
	if (g_spec->minus == 1)
	{
		if (g_spec->plus && !(part->is_neg))
			part->first[i++] = '+';
		if (part->is_neg)
			part->first[i++] = '-';
	}
	getfirst_min(part, &i, size_zero);
	part->first[i] = '\0';
}

void			getend(t_part *part)
{
	int			num_indents;
	int			size_buff;
	int			i;

	size_buff = part->middle->i + ft_strlen(part->first);
	if ((num_indents = g_spec->width - size_buff) < 0)
		return ;
	if ((part->last = (char *)malloc(sizeof(char) * (num_indents + 1))) == NULL)
		exit(-1);
	if (!(part->last))
		return ;
	part->last[num_indents] = '\0';
	i = 0;
	if (g_spec->minus == 0)
		part->last = NULL;
	else
	{
		while (i < num_indents)
		{
			part->last[i] = ' ';
			i++;
		}
	}
}
