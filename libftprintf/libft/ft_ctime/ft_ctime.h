/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:34:50 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 14:50:40 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTIME_H
# define FT_CTIME_H

# include "../includes/libft.h"
# include <time.h>

# define WEEKDAY_OF_JANUARY_1ST_1970 4
# define DEL_CTIME_UNIX_SYS 10800
# define START_YEAR	1970
# define NUMBER_OF_SPACES 7

typedef struct		s_cdate
{
	char			*weekday;
	int				weekday_n;
	char			*month;
	int				month_n;
	char			*day;
	int				day_n;
	char			*hour;
	int				hour_n;
	char			*min;
	int				min_n;
	char			*sec;
	int				sec_n;
	char			*year;
	int				year_n;
}					t_cdate;

char				*ft_ctime(const time_t *ttime);

void				free_uctime(t_cdate *date);
t_cdate				*ft_uctime(const time_t *ttime);

t_cdate				*struct_to_str(t_cdate *date);

t_cdate				*getday_since1970(t_cdate *date, \
	const time_t ttime, time_t *res);

t_cdate				*getweekday(t_cdate *date);
t_cdate				*gettime(t_cdate *date, const time_t *res);
t_cdate				*getyear(t_cdate *date, time_t ttime);
t_cdate				*getmonth(t_cdate *date);

#endif
