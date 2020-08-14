/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:51:44 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 17:01:03 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_str_is_int(char *line, int *number)
{
	long	n;
	int		i;
	int		ranks;
	int		zeros_is_skiped;

	zeros_is_skiped = 0;
	i = (line[0] == '-' || line[0] == '+') ? 0 : -1;
	if (i + 1 == (int)ft_strlen(line))
		return (EXIT_FAILURE);
	ranks = 0;
	while (++i < (int)ft_strlen(line))
	{
		if (line[i] < '0' || line[i] > '9')
			return (EXIT_FAILURE);
		if (line[i] == '0' && zeros_is_skiped == 0)
			continue;
		zeros_is_skiped = 1;
		ranks++;
	}
	if (ranks > 10)
		return (EXIT_FAILURE);
	if ((n = ft_atoi_base(line, 10)) < INT_MIN || n > INT_MAX)
		return (EXIT_FAILURE);
	*number = n;
	return (EXIT_SUCCESS);
}

t_list	*ft_lstp2top(t_list **begin_list, void const *content,\
size_t content_size)
{
	t_list *new_begin;

	new_begin = ft_lstnew(content, content_size);
	if (!*begin_list)
		return (*begin_list = new_begin);
	if (!new_begin)
		return (new_begin);
	ft_lstadd(begin_list, new_begin);
	return (*begin_list);
}
