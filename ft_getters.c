/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:57:08 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 07:00:10 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Get pointer from anthill->rooms to t_room structure
*/

t_room		*ft_get_room_from_anthill(t_list *rooms)
{
	if (rooms == NULL)
		return (NULL);
	return ((t_room *)(rooms->content));
}

/*
**	Get pointer from connected_rooms->content to anthil->rooms
*/

t_list		*ft_get_room_adress_from_connected(t_list *connected_rooms)
{
	t_link *link;
	t_list *room_adress;

	if (connected_rooms == NULL)
		return (NULL);
	link = (t_link *)connected_rooms->content;
	room_adress = link->room;
	return (room_adress);
}

/*
**	Get pointer connected_rooms->content
*/

t_link		*ft_get_link_from_connected(t_list *connected_rooms)
{
	t_link *link;

	if (connected_rooms == NULL)
		return (NULL);
	link = (t_link *)connected_rooms->content;
	return (link);
}

/*
**	Get pointer from anthill->connected_rooms to t_room structure
*/

t_room		*ft_get_room_from_connected(t_list *connected_rooms)
{
	t_list *node;
	t_room *room;

	if (connected_rooms == NULL)
		return (NULL);
	node = ft_get_room_adress_from_connected(connected_rooms);
	room = ft_get_room_from_anthill(node);
	return (room);
}

/*
**	Находит соответствующий link
*/

t_link		*ft_find_link(t_list *node, t_list *connected_room)
{
	t_room *room;
	t_list *head;

	room = ft_get_room_from_anthill(node);
	head = room->connected_rooms;
	while (head && ft_get_room_adress_from_connected(head) != connected_room)
	{
		head = head->next;
	}
	return (ft_get_link_from_connected(head));
}
