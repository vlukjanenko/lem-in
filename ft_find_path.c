/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:18:06 by majosue           #+#    #+#             */
/*   Updated: 2020/07/16 06:50:04 by majosue          ###   ########.fr       */
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
		head2 = ft_get_room_from_anthill(head)->connected_rooms;
		while (head2)
		{
			printf("%s - %s flow [%d][%d]\n", ((t_room *)(head->content))->name, ft_get_room_from_connected(head2)->name, ft_get_link_from_connected(head2)->flow, ft_get_link_from_connected(head2)->disable);
			head2 = head2->next;
		}
		printf("\n");
		head = head->next;
	}
}

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

/* int ft_get_flow_from_connected(t_list *connected_rooms)
{
	t_link link;
	int flow;
	if (connected_rooms == NULL)
		return -1;
	link = *(t_link *)connected_rooms->content;
	flow = link.flow;
	return (flow);
} */

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
	t_list *tmp;
	//int count_sutable;

	room = anthill->end_room;							// берём адресок конца из t_list rooms
	while (room != anthill->start_room) // пока не добрались до старта
	{
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список соседних комнат (список адресов)
		tmp = rooms;
		/* count_sutable = 0;
		while (tmp) 
		{
			if (ft_get_room_adress_from_connected(tmp) == ft_get_room_from_anthill(room)->from_room)
				count_sutable++;			
			tmp = tmp->next;
		}
		printf("[Sutable path to move - %d]", count_sutable); */
		while (rooms)
		{
/* 			if (ft_get_room_from_anthill(room)->visited - ft_get_room_from_connected(rooms)->visited == 1 && ft_find_link(ft_get_room_adress_from_connected(rooms), room)->flow == 0)
 */			
			if (ft_get_room_adress_from_connected(rooms) == ft_get_room_from_anthill(room)->from_room)
			{
				ft_find_link(ft_get_room_adress_from_connected(rooms), room)->flow = 1;
				/* if (ft_get_link_from_connected(rooms)->flow == 1)
				{
					printf("find block\n");
					ft_find_link(ft_get_room_adress_from_connected(rooms), room)->disable = 1;
					ft_get_link_from_connected(rooms)->disable = 1;
					return (-1);
				} */
				printf("%s <- ", ft_get_room_from_anthill(room)->name);
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
	ft_run_ant(anthill);
	return (EXIT_SUCCESS);
}

int ft_find_augmenting_path(t_anthill *anthill)
{
	t_list *queue;
	t_list *room;
	t_list *rooms;
		
	queue = NULL;
	ft_get_room_from_anthill(anthill->start_room)->visited = 0;
	ft_lstp2back(&queue, &anthill->start_room, sizeof(room)); // кладём адресок в очередь
	while (queue)							   // пока очередь не пуста
	{
		room = ft_dequeue(&queue);								 // берем адрес комнаты из очереди
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список адресов соседних комнат
		while (rooms)
		{
			if (ft_get_room_from_connected(rooms)->visited == -1 && ft_get_link_from_connected(rooms)->flow == 0 && ft_get_link_from_connected(rooms)->disable == 0 /* && ft_get_room_from_connected(rooms)->room_flow == 0 */)
			{
				ft_get_room_from_connected(rooms)->visited = ft_get_room_from_anthill(room)->visited + 1;
				ft_get_room_from_connected(rooms)->from_room = room;
				ft_lstp2back(&queue, &ft_get_link_from_connected(rooms)->room, sizeof(room));
				if (ft_get_link_from_connected(rooms)->room == anthill->end_room)
				{
					ft_lstdel(&queue, del);
					return (ft_mark_path(anthill));
				}
			}		
			rooms = rooms->next;
		}
	}
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

void ft_reset_visited(t_list *lst)
{
	/* t_list *head;
	head = anthill->rooms;
	while (head)
	{ */
		ft_get_room_from_anthill(lst)->visited = -1;
		ft_get_room_from_anthill(lst)->from_room = NULL;
	/* 	head = head->next;
	} */
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
	ft_lstiter(anthill->rooms, ft_reset_visited);
	max_flow = 0;

	int result;
	//ft_print_graf(anthill);
	//ft_find_augmenting_path(anthill);
	while (1)
	{
		//ft_print_graf(anthill);
		result = ft_find_augmenting_path(anthill);
		if (result == -1)
		{
			ft_reset_flows(anthill);
			ft_lstiter(anthill->rooms, ft_reset_visited);
			max_flow = 0;
		} 
		else if (result == 1)
		{
			max_flow++;
			if (max_flow == max)
				break;
			ft_lstiter(anthill->rooms, ft_reset_visited);
		}
		else if (result == 0)
			break;
	}
printf("Maxflow = %d\n", max_flow);
//ft_reset_flows(anthill);

return (1);
}