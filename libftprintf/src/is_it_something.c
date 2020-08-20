/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_something.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:40:01 by oargrave          #+#    #+#             */
/*   Updated: 2019/08/02 14:47:02 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					is_badsymb(char c)
{
	if (c == ' ' || c == '.' || c == '0' || c == '+' || c == '-' || \
		c == '#' || c == 'h' || c == 'l' || c == 'L' || c == 'z' || \
		c == 'j' || ft_isdigit(c) == 1)
		return (0);
	return (1);
}

int					is_calculatesymb(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == '.')
		return (1);
	return (0);
}

int					is_lh_bigl(char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}

int					is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' || \
		c == 'e' || c == 'g' || c == 'b' || c == 'r' || c == 'k' || \
		c == '%' || c == 'U' || c == 'O' || c == 'S' || c == 'C' || \
		c == 'D' || c == 'F' || c == 'w')
		return (1);
	else
		return (0);
}
