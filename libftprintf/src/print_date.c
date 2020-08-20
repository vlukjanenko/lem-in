/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:55:46 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 15:08:58 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				print_date(void)
{
	time_t			ttime;
	char			*time_str;

	ttime = time(NULL);
	time_str = ft_ctime(&ttime);
	ft_buffadd(g_output, time_str);
	ft_strdel(&time_str);
}
