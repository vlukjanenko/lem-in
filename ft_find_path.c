/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:18:06 by majosue           #+#    #+#             */
/*   Updated: 2020/05/03 18:22:00 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_list *room_adress(t_list *list)
{
	if (list == NULL)
		return NULL;
	return (*(t_list**)(list->content));
}

t_room *ft_get_room_from_connected(t_list *connected_rooms)
{
	if (connected_rooms == NULL)
		return NULL;
	return (((t_room*)(*(t_list**)(connected_rooms->content))->content));
}

t_room *ft_get_room_from_anthill(t_list *rooms)
{
	if (rooms == NULL)
		return NULL;
	return ((t_room*)(rooms->content));
}
int ft_run_ant(t_anthill *anthill)
{
	t_list *room;
	t_list *rooms;

	room = ft_get_room_adress(anthill->end_room, anthill); // берём адресок конца из t_list rooms
	while (ft_get_room_from_anthill(room)->visited > 0) // пока не добрались до старта
	{
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список соседних комнат (список адресов)
		while (rooms)
		{
			if (ft_get_room_from_anthill(room)->visited - ft_get_room_from_connected(rooms)->visited == 1)
			{		
				printf("%s -> ", ft_get_room_from_anthill(room)->name);
				room = *(t_list**)(rooms->content);
				break ;
			}
			rooms = rooms->next;
		}
	}
	printf("%s\n", ft_get_room_from_anthill(room)->name);
	return (EXIT_SUCCESS);
}

int ft_find_path(t_anthill *anthill)
{
	t_list *queue;
	t_list *room;
	t_list *rooms;

	queue = NULL;
	room = ft_get_room_adress(anthill->start_room, anthill); // берём адресок из t_list rooms
	ft_get_room_from_anthill(room)->visited = 0;
	ft_lstp2back(&queue, &room, sizeof(room)); // кладём адресок в очередь
	while (queue) // пока очередь не пуста
	{
		room = ft_dequeue(&queue); // берем адрес комнаты из очереди
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список адресов соседних комнат
		while (rooms)
		{
			if (ft_get_room_from_connected(rooms)->visited == -1)
			{
				ft_get_room_from_connected(rooms)->visited = ft_get_room_from_anthill(room)->visited + 1;
				ft_lstp2back(&queue, &(*(t_list**)(rooms->content)), sizeof(rooms));
			}
			rooms = rooms->next;
		}
	}
	//ft_print_graf(anthill);
	ft_run_ant(anthill);
	return (EXIT_SUCCESS);
}
