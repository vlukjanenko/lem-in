/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:18:06 by majosue           #+#    #+#             */
/*   Updated: 2020/08/13 21:42:49 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**	Сброс потоков у всех ребер в 0
*/

void	ft_reset_flows(t_anthill *anthill)
{
	t_list *head;
	t_list *head2;

	head = anthill->rooms;
	while (head)
	{
		head2 = ft_get_room_from_anthill(head)->connected_rooms;
		while (head2)
		{
			ft_get_link_from_connected(head2)->flow = 0;
			head2 = head2->next;
		}
		head = head->next;
	}
}

/*
**	Сброс посещенных у всех комнат в 0
*/

void	ft_reset_visited(t_list *lst)
{
	ft_get_room_from_anthill(lst)->visited = -1;
	ft_get_room_from_anthill(lst)->from_room = NULL;
}

void	ft_find_path(t_anthill *anthill)
{
	int		result;
	t_list	*start;

	start = anthill->start_room;
	anthill->start_room = anthill->start_room->next;
	ft_lstiter(anthill->rooms, ft_reset_visited);
	while (1)
	{
		result = ft_find_augmenting_path(anthill);
		if (result == 1)
			ft_lstiter(anthill->rooms, ft_reset_visited);
		else if (result == 0 && anthill->block == 1)
		{
			ft_add_path_set(anthill);
			ft_reset_flows(anthill);
			ft_lstiter(anthill->rooms, ft_reset_visited);
			anthill->number_lines = -1;
			anthill->block = 0;
		}
		else
			break ;
	}
	anthill->start_room = start;
}
