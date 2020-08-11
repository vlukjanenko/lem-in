/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:34:22 by majosue           #+#    #+#             */
/*   Updated: 2019/12/16 20:16:31 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_cleanup(void *content, size_t content_size)
{
	if (content)
	{
		ft_bzero(content, content_size);
		ft_memdel(&content);
	}
}

int		ft_printstr(t_list *str)
{
	int n;

	if (!str)
		return (0);
	n = 0;
	while (str)
	{
		write(1, (char *)str->content, str->content_size);
		n = n + str->content_size;
		str = str->next;
	}
	return (n);
}

int		ft_format(t_list **str, t_list *begin, va_list ap)
{
	char	tmp;
	t_fun	f;

	begin = *str;
	while (begin)
	{
		if (((char *)begin->content)[0] == '%')
		{
			tmp = ((char *)begin->content)[begin->content_size - 1];
			f = ft_get_f(tmp);
			if (!(f(&begin, ap)))
				return (0);
		}
		begin = begin->next;
	}
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	t_list	*str;
	va_list ap;
	void	(*del)(void *, size_t);
	int		n;

	del = &ft_cleanup;
	str = 0;
	if (ft_readformat(&str, (char *)format) == -1)
	{
		str ? ft_lstdel(&str, del) : str;
		return (0);
	}
	va_start(ap, format);
	if (ft_format(&str, 0, ap) == 0)
	{
		str ? ft_lstdel(&str, del) : str;
		return (0);
	}
	va_end(ap);
	n = ft_printstr(str);
	str ? ft_lstdel(&str, del) : str;
	return (n);
}
