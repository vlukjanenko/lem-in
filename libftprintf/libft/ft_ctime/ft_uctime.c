/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uctime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:06:13 by yquaro            #+#    #+#             */
/*   Updated: 2019/07/25 13:40:11 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

static t_cdate		*nullifydate(void)
{
	t_cdate *date;

	date = (t_cdate *)ft_memalloc(sizeof(t_cdate));
	date->weekday = NULL;
	date->weekday_n = 0;
	date->month = NULL;
	date->month_n = 0;
	date->day = NULL;
	date->day_n = 0;
	date->hour = NULL;
	date->hour_n = 0;
	date->min = NULL;
	date->min_n = 0;
	date->sec = NULL;
	date->sec_n = 0;
	date->year = NULL;
	date->year_n = 0;
	return (date);
}

void				free_uctime(t_cdate *date)
{
	if (date->weekday != NULL)
		ft_strdel(&(date->weekday));
	if (date->month != NULL)
		ft_strdel(&(date->month));
	if (date->day != NULL)
		ft_strdel(&(date->day));
	if (date->hour != NULL)
		ft_strdel(&(date->hour));
	if (date->min != NULL)
		ft_strdel(&(date->min));
	if (date->sec != NULL)
		ft_strdel(&(date->sec));
	if (date->year != NULL)
		ft_strdel(&(date->year));
	free(date);
	date = NULL;
}

t_cdate				*ft_uctime(const time_t *ttime)
{
	time_t		tsec;
	t_cdate		*date;
	time_t		res;

	if (*ttime < 0)
	{
		ft_putstr("ERROR: ft_uctime does not work with negative numbers\n");
		exit(-1);
	}
	res = 0;
	tsec = (time_t)*ttime + DEL_CTIME_UNIX_SYS;
	date = nullifydate();
	date = getday_since1970(date, tsec, &res);
	date = getweekday(date);
	date = gettime(date, (const time_t *)&res);
	date = getyear(date, tsec);
	date = getmonth(date);
	date = struct_to_str(date);
	return (date);
}
