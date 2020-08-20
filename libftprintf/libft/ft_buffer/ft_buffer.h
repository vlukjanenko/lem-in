/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:51:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 16:27:21 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFER_H
# define FT_BUFFER_H

# include "../includes/libft.h"

typedef struct			s_buff
{
	char				*str;
	int					i;
	int					totalsize;
	int					additional_size;
}						t_buff;

t_buff					*ft_buffinit(int size);
void					ft_buffaddsymb(t_buff *buff, char c);
void					ft_buffadd(t_buff *buff, const char *str);
void					ft_buffladd(t_buff *buff, const char *str, int len);
void					ft_buffdel(t_buff **buff);

#endif
