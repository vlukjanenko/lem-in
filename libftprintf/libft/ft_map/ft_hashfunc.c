/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:11:40 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/07 06:27:31 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#define MIN_LONG_LONG -9223372036854775807

static long long		aabs(long long num)
{
	if (num == MIN_LONG_LONG)
		return (-(num + 1));
	else if (num < 0)
		return (-num);
	else
		return (num);
}

int						ft_hashfunc(const char *str, int size)
{
	int			i;
	long long	hash;
	int			p;
	long long	p_pow;

	p_pow = 1;
	i = 0;
	hash = 0;
	p = 16;
	while (str[i] != '\0')
	{
		hash += (str[i] - 'a' + 1) * p_pow;
		p_pow *= p;
		i++;
	}
	hash = aabs(hash);
	if (hash < 0)
		hash = aabs(hash) % size;
	else
		hash = hash % size;
	return (hash);
}
