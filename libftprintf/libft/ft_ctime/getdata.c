/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:26:35 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/04 19:18:41 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

static int	leapsyear(int year)
{
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		return (366);
	return (365);
}

t_cdate		*getyear(t_cdate *date, time_t ttime)
{
	int		tmp;
	int		day;
	int		year;

	day = 0;
	year = START_YEAR - 1;
	tmp = ((int)ttime) / (60 * 60 * 24);
	while (day <= tmp)
	{
		year++;
		day += leapsyear(year);
	}
	date->day_n = leapsyear(year) - (day - tmp) + 1;
	date->year_n = year;
	return (date);
}

t_cdate		*gettime(t_cdate *date, const time_t *res)
{
	time_t	min;
	time_t	sec;
	time_t	hour;

	min = *res / 60;
	sec = *res - (min * 60);
	hour = min / 60;
	min = min - (hour * 60);
	date->hour_n = (int)hour;
	date->min_n = (int)min;
	date->sec_n = (int)sec;
	return (date);
}

t_cdate		*getweekday(t_cdate *date)
{
	time_t	weekday;
	time_t	tmp;

	weekday = date->day_n / 7;
	tmp = date->day_n - (weekday * 7);
	date->weekday_n = WEEKDAY_OF_JANUARY_1ST_1970 + tmp;
	if (date->weekday_n > 7)
		date->weekday_n -= 7;
	return (date);
}
