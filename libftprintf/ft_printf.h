/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:17:59 by majosue           #+#    #+#             */
/*   Updated: 2019/12/17 13:05:58 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef int	(*t_fun)(t_list **, va_list);

typedef union	u_type {
	int				i;
	char			c;
	short int		si;
	long int		li;
	long long int	lli;
}				t_type;

typedef union	u_type_u {
	unsigned int			i;
	unsigned char			c;
	unsigned short int		si;
	unsigned long int		li;
	unsigned long long int	lli;
}				t_type_u;

int				ft_printf(const char *restrict format, ...);
int				ft_chkflags(char **str, char *ftab[5]);
int				ft_lstp2back(t_list **begin_list, void const *content,\
size_t content_size);
int				ft_readformat(t_list **str, char *format);
t_fun			ft_get_f(char c);
/*
** conversion functions start
*/
int				ft_char(t_list **str, va_list ap);
int				ft_string(t_list **str, va_list ap);
int				ft_pointer(t_list **str, va_list ap);
int				ft_number(t_list **str, va_list ap);
int				ft_number_o(t_list **str, va_list ap);
int				ft_number_u(t_list **str, va_list ap);
int				ft_number_x(t_list **str, va_list ap);
int				ft_float(t_list **str, va_list ap);
/*
** conversion functions end
*/
int				ft_compare(char *flags, char c);
void			ft_gettab(char *(*ftab)[5], int index);
void			ft_add_left(t_list **str, void **newstr, size_t w, char c);
void			ft_add_right(t_list **str, void **newstr, size_t w, char c);
int				ft_null(char *str);
int				ft_space(char *str);
int				ft_minus(char *str);
int				ft_plus(char *str);
int				ft_skipflags(char **str);
int				ft_width(char *str, size_t *w);
int				ft_prec(char *str, size_t *p);
int				ft_fmt_char(t_list **str, char *s);
int				ft_fmt_plus(t_list **str, char *s);
int				ft_fmt_width(t_list **str, char *s);
int				ft_fmt_prec(t_list **str, char *s);
char			*ft_itoa_base(long long int value, int base);
char			*ft_itoa_base_u(unsigned long long int value, int base);
char			*ft_ftoa(long double n, int p);
void			ft_get_size(char *str, long long int *d, va_list ap);
void			ft_get_size_u(char *str, unsigned long long int *d, va_list ap);
int				ft_sharp(char *s);

#endif
