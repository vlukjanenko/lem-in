/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:43:32 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 15:04:34 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_strglue(char *puthere, ...)
{
	va_list			arg;
	int				counter;
	int				i;
	char			*str;

	if (puthere == NULL)
		return ;
	va_start(arg, (char *)puthere);
	counter = ft_strlen(puthere);
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
