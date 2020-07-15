/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:18:06 by majosue           #+#    #+#             */
/*   Updated: 2020/07/14 22:07:29 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
void ft_print_graf(t_anthill *anthill)
{
	t_list *head;
	t_list *head2;
	head = anthill->rooms;
	while (head)
	{
		//printf("Room - %s , level - %d, conected rooms - [", ((t_room*)(head->content))->name, ((t_room*)(head->content))->visited);
		head2 = ((t_room *)(head->content))->connected_rooms;
		while (head2)
		{
			printf("%s - %s flow [%d][%d]\n", ((t_room *)(head->content))->name, ft_get_room_from_connected(head2)->name, ft_get_flow_from_connected(head2), ft_get_link_from_connected(head2)->disable);
			head2 = head2->next;
		}
		printf("\n");
		head = head->next;
	}
}

/* t_list *room_adress(t_list *list)
{
	if (list == NULL)
		return NULL;
	return (*(t_list**)(list->content));
} */

t_room *ft_get_room_from_anthill(t_list *rooms)
{
	if (rooms == NULL)
		return NULL;
	return ((t_room *)(rooms->content));
}

t_list *ft_get_room_adress_from_connected(t_list *connected_rooms)

{
	t_link *link;
	t_list *room_adress;
	if (connected_rooms == NULL)
		return NULL;
	link = (t_link *)connected_rooms->content;
	room_adress = link->room;
	return (room_adress);
}

t_link *ft_get_link_from_connected(t_list *connected_rooms)

{
	t_link *link;
	if (connected_rooms == NULL)
		return NULL;
	link = (t_link *)connected_rooms->content;
	return (link);
}

t_room *ft_get_room_from_connected(t_list *connected_rooms)
{
	t_list *node;
	t_room *room;
	if (connected_rooms == NULL)
		return NULL;
	node = ft_get_room_adress_from_connected(connected_rooms);
	room = ft_get_room_from_anthill(node);
	return (room);
}

int ft_get_flow_from_connected(t_list *connected_rooms)
{
	t_link link;
	int flow;
	if (connected_rooms == NULL)
		return -1;
	link = *(t_link *)connected_rooms->content;
	flow = link.flow;
	return (flow);
}

int ft_run_ant(t_anthill *anthill)
{
	t_list *room;
	t_list *rooms;

	room = anthill->end_room;							// берём адресок конца из t_list rooms
	while (ft_get_room_from_anthill(room)->visited > 0) // пока не добрались до старта
	{
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список соседних комнат (список адресов)
		while (rooms)
		{
			if (ft_get_room_from_anthill(room)->visited - ft_get_room_from_connected(rooms)->visited == 1)
			{
				printf("%s -> ", ft_get_room_from_anthill(room)->name);
				room = *(t_list **)(rooms->content);
				break;
			}
			rooms = rooms->next;
		}
	}
	printf("%s\n", ft_get_room_from_anthill(room)->name);
	return (EXIT_SUCCESS);
}

t_link *ft_find_link(t_list *node, t_list *connected_room) //стоп стоп стоп тут какраз комната не линк второй аргумент
{
	t_room *room;
	t_list *head;

	room = ft_get_room_from_anthill(node);
	head = room->connected_rooms;
	while (ft_get_room_adress_from_connected(head) != connected_room)
	{
		head = head->next;
	}
	return (ft_get_link_from_connected(head));
}

int ft_mark_path(t_anthill *anthill)
{
	t_list *room;
	t_list *rooms;

	room = anthill->end_room;							// берём адресок конца из t_list rooms
	while (ft_get_room_from_anthill(room)->visited > 0) // пока не добрались до старта
	{
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список соседних комнат (список адресов)
		while (rooms)
		{
			if (ft_get_room_from_anthill(room)->visited - ft_get_room_from_connected(rooms)->visited == 1)
			{
				ft_find_link(ft_get_room_adress_from_connected(rooms), room)->flow = 1;
				if (ft_get_link_from_connected(rooms)->flow == 1)
				{
					printf("find block\n");
					ft_find_link(ft_get_room_adress_from_connected(rooms), room)->disable = 1;
					ft_get_link_from_connected(rooms)->disable = 1;
					return (-1);
				}
				printf("%s -> ", ft_get_room_from_anthill(room)->name);
				/* room = *(t_list**)(rooms->content); */
				ft_get_room_from_connected(rooms)->room_flow = 1;
				room = ft_get_room_adress_from_connected(rooms);
				break;
			}
			rooms = rooms->next;
		}
	}
	printf("%s\n", ft_get_room_from_anthill(room)->name);
	return (1);
}

int ft_find_path(t_anthill *anthill)
{
	t_list *queue;
	t_list *room;
	t_list *rooms;

	queue = NULL;
	room = anthill->start_room; // берём адресок из t_list rooms
	ft_get_room_from_anthill(room)->visited = 0;
	ft_lstp2back(&queue, &room, sizeof(room)); // кладём адресок в очередь
	while (queue)							   // пока очередь не пуста
	{
		room = ft_dequeue(&queue);								 // берем адрес комнаты из очереди
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список адресов соседних комнат
		while (rooms)
		{
			if (ft_get_room_from_connected(rooms)->visited == -1)
			{
				ft_get_room_from_connected(rooms)->visited = ft_get_room_from_anthill(room)->visited + 1;
				ft_lstp2back(&queue, &(*(t_list **)(rooms->content)), sizeof(rooms));
			}
			rooms = rooms->next;
		}
	}
	//ft_print_graf(anthill);
	ft_run_ant(anthill);
	return (EXIT_SUCCESS);
}

int ft_find_augmenting_path(t_anthill *anthill)
{
	t_list *queue;
	t_list *room;
	t_list *rooms;
	t_list *current_room;

	queue = NULL;
	room = anthill->start_room; // берём адресок из t_list rooms
	ft_get_room_from_anthill(room)->visited = 0;
	ft_lstp2back(&queue, &room, sizeof(room)); // кладём адресок в очередь
	while (queue)							   // пока очередь не пуста
	{
		room = ft_dequeue(&queue);								 // берем адрес комнаты из очереди
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список адресов соседних комнат
		while (rooms)
		{
			current_room = ft_get_room_adress_from_connected(rooms);
			//printf("Curroom %p\nEndroom %p\n", current_room, anthill->end_room);

			if (ft_get_room_from_connected(rooms)->visited == -1 && ft_get_link_from_connected(rooms)->flow == 0 && ft_get_link_from_connected(rooms)->disable == 0 && ft_get_room_from_connected(rooms)->room_flow == 0)
			{
				ft_get_room_from_connected(rooms)->visited = ft_get_room_from_anthill(room)->visited + 1;
				ft_lstp2back(&queue, &current_room, sizeof(current_room));
				if (current_room == anthill->end_room)
				{
					//printf("come to mark");
					ft_lstdel(&queue, del);
					//ft_mark_path(anthill);
					return (ft_mark_path(anthill));
					//ft_print_graf(anthill);
					//printf("------------------------------------------\n");
					//return (1);
				}
			}
			rooms = rooms->next;
		}
	}
	//ft_mark_path(anthill);
	//ft_print_graf(anthill);
	//printf("------------------------------------------\n");
	//ft_run_ant(anthill);
	return (0);
}

void ft_reset_flows(t_anthill *anthill)
{
	t_list *head;
	t_list *head2;

	head = anthill->rooms;
	while (head)
	{
		ft_get_room_from_anthill(head)->room_flow = 0;
		head2 = ft_get_room_from_anthill(head)->connected_rooms;
		while (head2)
		{
			ft_get_link_from_connected(head2)->flow = 0;
			head2 = head2->next;
		}
		head = head->next;
	}
}

void ft_reset_visited(t_anthill *anthill)
{
	t_list *head;
	head = anthill->rooms;
	while (head)
	{
		ft_get_room_from_anthill(head)->visited = -1;
		head = head->next;
	}
}

int ft_get_number_links(t_list *lst)
{
	int number;

	number = 0;
	while (lst)
	{
		number++;
		lst = lst->next;
	}
	return (number);
}

int ft_karp(t_anthill *anthill)
{
	int max_flow;
	int links_start;
	int links_end;
	int max;

	links_start = ft_get_number_links(ft_get_room_from_anthill(anthill->start_room)->connected_rooms);
	links_end = ft_get_number_links(ft_get_room_from_anthill(anthill->end_room)->connected_rooms);
	max = links_start < links_end ? links_start : links_end;
	printf("MAX %d\n", max);
	ft_reset_visited(anthill);
	max_flow = 0;

	int result;
	//ft_print_graf(anthill);
	//ft_find_augmenting_path(anthill);
	while (1)
	{
		result = ft_find_augmenting_path(anthill);
		if (result == -1)
		{
			ft_reset_flows(anthill);
			ft_reset_visited(anthill);
			max_flow = 0;
		} 
		else if (result == 1)
		{
			max_flow++;
			if (max_flow == max)
				break;
			ft_reset_visited(anthill);
		}
		else if (result == 0)
			break;
	}
printf("Maxflow = %d\n", max_flow);
//ft_reset_flows(anthill);
//ft_print_graf(anthill);
return (1);
}