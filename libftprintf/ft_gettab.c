/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:47:20 by majosue           #+#    #+#             */
/*   Updated: 2019/11/27 17:49:08 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fill flags array
** index < 5 exact element
** index = 5 all elements
** index > 5 empty array
*/

void	ft_gettab(char *(*ftab)[5], int index)
{
	(*ftab)[0] = "";
	(*ftab)[1] = "";
	(*ftab)[2] = "";
	(*ftab)[3] = "";
	(*ftab)[4] = "";
	if (index == 0 || index == 5)
		(*ftab)[0] = " #0-+";
	if (index == 1 || index == 5)
		(*ftab)[1] = "0123456789";
	if (index == 2 || index == 5)
		(*ftab)[2] = ".0123456789";
	if (index == 3 || index == 5)
		(*ftab)[3] = "hlL";
	if (index == 4 || index == 5)
		(*ftab)[4] = "cspdiouxXf%";
}
