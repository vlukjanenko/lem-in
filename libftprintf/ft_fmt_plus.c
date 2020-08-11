/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:06:51 by majosue           #+#    #+#             */
/*   Updated: 2019/11/29 13:08:53 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fmt_plus(t_list **str, char *s)
{
	size_t	w;
	void	*newstr;
	char	c;

	if ((ft_plus(s) || ft_space(s)) && ft_isdigit(((char *)(*str)->content)[0]))
	{
		if ((w = (*str)->content_size + 1) < (*str)->content_size)
			return (0);
		if (!(newstr = ft_memalloc(w)))
			return (0);
		if (ft_plus(s))
			c = '+';
		else
			c = ' ';
		ft_add_left(str, &newstr, w, c);
		free((*str)->content);
		(*str)->content = newstr;
		(*str)->content_size = w;
	}
	return (1);
}
