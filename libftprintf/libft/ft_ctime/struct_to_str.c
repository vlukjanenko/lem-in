/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:08:49 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/04 19:17:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

static char			*digit_to_str(int num)
{
	char	*str;
	int		len;

	len = ft_numblen(num);
	if (len < 1 || len > 2)
		return (NULL);
	if (len == 1)
	{
		str = (char *)ft_memalloc(3);
		str[0] = '0';
		str[1] = num + '0';
		str[2] = '\0';
	}
	else
		return (ft_itoa(num));
	return (str);
}

static const char	*whatsmonth(int month)
{
	if (month == 1)
		return ("Jan");
	if (month == 2)
		return ("Feb");
	if (month == 3)
		return ("Mar");
	if (month == 4)
		return ("Apr");
	if (month == 5)
		return ("May");
	if (month == 6)
		return ("Jun");
	if (month == 7)
		return ("Jul");
	if (month == 8)
		return ("Aug");
	if (month == 9)
		return ("Sep");
	if (month == 10)
		return ("Oct");
	if (month == 11)
		return ("Nov");
	if (month == 12)
		return ("Dec");
	return (NULL);
}

static const char	*whatsday(int weekday)
{
	if (weekday == 1)
		return ("Mon");
	if (weekday == 2)
		return ("Tue");
	if (weekday == 3)
		return ("Wed");
	if (weekday == 4)
		return ("Thu");
	if (weekday == 5)
		return ("Fri");
	if (weekday == 6)
		return ("Sat");
	if (weekday == 7)
		return ("Sun");
	return (NULL);
}

t_cdate				*struct_to_str(t_cdate *date)
{
	date->weekday = ft_strdup(whatsday(date->weekday_n));
	date->month = ft_strdup(whatsmonth(date->month_n));
	date->day = ft_itoa(date->day_n);
	date->hour = digit_to_str(date->hour_n);
	date->min = digit_to_str(date->min_n);
	date->sec = digit_to_str(date->sec_n);
	date->year = ft_itoa(date->year_n);
	return (date);
}
