/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_augmenting_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:26:05 by majosue           #+#    #+#             */
/*   Updated: 2020/08/13 21:28:45 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_is_room_visitable(t_list *rooms)
{
	return (ft_get_room_from_connected(rooms)->visited == -1 &&
			ft_get_link_from_connected(rooms)->\
			capacity - ft_get_link_from_connected(rooms)->flow == 1 &&
			ft_get_link_from_connected(rooms)->disable == 0);
}

void	ft_visit(t_list *rooms, t_list *room, t_list **queue)
{
	ft_get_room_from_connected(rooms)->\
	visited = ft_get_room_from_anthill(room)->visited + 1;
	ft_get_room_from_connected(rooms)->from_room = room;
	ft_enqueue(queue, &ft_get_link_from_connected(rooms)->room);
}

int		ft_clean_queue_and_mark_path(t_list **queue, t_anthill *anthill)
{
	ft_lstdel(queue, del);
	return (ft_mark_path(anthill));
}

/*
**	Поиск дополнительного пути
*/

int		ft_find_augmenting_path(t_anthill *anthill)
{
	t_list *queue;
	t_list *room;
	t_list *rooms;

	queue = NULL;
	ft_get_room_from_anthill(anthill->start_room)->visited = 0;
	ft_enqueue(&queue, &anthill->start_room);
	while (queue)
	{
		room = ft_dequeue(&queue);
		rooms = ft_get_room_from_anthill(room)->connected_rooms;
		while (rooms)
		{
			if (ft_is_room_visitable(rooms))
			{
				ft_visit(rooms, room, &queue);
				if (ft_get_link_from_connected(rooms)->\
				room == anthill->end_room)
					return (ft_clean_queue_and_mark_path(&queue, anthill));
			}
			rooms = rooms->next;
		}
	}
	return (0);
}
