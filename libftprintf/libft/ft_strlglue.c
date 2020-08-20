/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlglue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:18:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 15:04:43 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_strlglue(int start, char *puthere, ...)
{
	va_list			arg;
	int				counter;
	int				i;
	char			*str;

	if (puthere == NULL)
		return ;
	va_start(arg, (char *)puthere);
	counter = start;
	while (1)
	{
		if ((str = va_arg(arg, char*)) == NULL)
			break ;
		i = 0;
		while (str[i] != '\0')
			puthere[counter++] = str[i++];
	}
	va_end(arg);
}
