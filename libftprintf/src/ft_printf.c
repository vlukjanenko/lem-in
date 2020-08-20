/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:58:05 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/03 19:38:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int			take_str_before_persent(char **traverse)
{
	char			*trav;

	trav = *traverse;
	while (*trav != '%' && *trav != '\0')
	{
		if (*trav == '{')
		{
			take_color(&trav);
			continue ;
		}
		ft_buffaddsymb(g_output, *trav);
		trav++;
	}
	*traverse = trav;
	if (*trav == '\0')
		return (END_OF_STRING);
	return (0);
}

static void			output(size_t *size)
{
	*size = g_output->i;
	write(1, g_output->str, g_output->i);
}

static void			totalfree(void)
{
	ft_buffdel(&g_output);
	widthfree();
	gspecfree();
}

int					ft_printf(const char *format, ...)
{
	va_list			arg;
	char			*traverse;
	size_t			size;

	if (!(traverse = (char *)format))
		return (0);
	g_output = ft_buffinit(40);
	g_spec = NULL;
	va_start(arg, (char *)format);
	while (*traverse != '\0')
	{
		init_gspec();
		init_width();
		if (take_str_before_persent(&traverse) == END_OF_STRING)
			break ;
		struct_spec(&traverse);
		print_arg(arg);
	}
	output(&size);
	totalfree();
	va_end(arg);
	return (size);
}
