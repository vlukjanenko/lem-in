/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:43:15 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 08:02:04 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long	ft_atoi_base(const char *nbr, unsigned int base)
{
	long	r;
	int		sign;
	char	d;

	if (base > 16 || base < 2)
		return (0);
	r = 0;
	while (*nbr == '\t' || *nbr == '\n' || *nbr == '\v' || *nbr == '\f' ||\
	*nbr == '\r' || *nbr == ' ')
		nbr++;
	sign = (*nbr == '+' || *nbr == '-') ? 44 - *nbr++ : 1;
	if (base <= 10)
		while ((d = *nbr++) >= '0' && d <= '0' + (int)base)
			r = r * base + d - '0';
	if (base > 10)
	{
		while (((d = *nbr++) >= '0' && d <= '9') || (d >= 'A' && d <= 'A' +\
		((int)base - 10)) || (d >= 'a' && d <= 'a' + ((int)base - 10)))
		{
			r = (d <= '9') ? r * base + d - '0' : r;
			r = (d >= 'A' && d <= 'F') ? r * base + d - 'A' + 10 : r;
			r = (d >= 'a' && d <= 'f') ? r * base + d - 'a' + 10 : r;
		}
	}
	return (r * sign);
}

/*
**	Try to find existing room name in anthill
*/

t_list	*ft_get_room_adress(char *name, t_anthill *anthill)
{
	t_list *head;

	head = anthill->rooms;
	while (head)
	{
		if (ft_strequ(((t_room*)(head->content))->name, name))
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_list	*ft_get_last_room_adress(t_list *rooms)
{
	while (rooms->next->next)
		rooms = rooms->next;
	return (rooms);
}

/*
**	Free ft_strsplit created array
*/

void	ft_clean_array(char ***array)
{
	char **tmp;

	if (*array)
	{
		tmp = *array;
		while (**array)
		{
			free(**array);
			(*array)++;
		}
		free(tmp);
	}
}

/*
**	Return size of array, that ends with NULL
*/

int		ft_array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
