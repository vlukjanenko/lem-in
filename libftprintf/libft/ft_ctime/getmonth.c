/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmonth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:18:27 by yquaro            #+#    #+#             */
/*   Updated: 2019/05/04 19:41:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctime.h"

static int	leapsyear(int year)
{
	if ((year % 4 == 0 && year % 100) || year % 400 == 0)
		return (366);
	return (365);
}

static int	daysinmonth(t_cdate *date, int month)
{
	int num;

	num = 0;
	if (month == 2)
	{
		if (leapsyear(date->year_n) == 366)
			num = 29;
		else
			num = 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || \
				month == 8 || month == 10 || month == 12)
		num = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		num = 30;
	return (num);
}

t_cdate		*getmonth(t_cdate *date)
{
	int	month;
	int	day;

	month = 0;
	day = 0;
	while (day < date->day_n)
	{
		month++;
		day += daysinmonth(date, month);
	}
	date->month_n = month;
	date->day_n = daysinmonth(date, month) - (day - date->day_n);
	return (date);
}
