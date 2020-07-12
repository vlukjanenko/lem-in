/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/07/11 22:30:02 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_list *ft_get_adress_from_content(t_list *list)
{
	if (list == NULL)
		return NULL;
	return ((*(t_list**)(list->content))->content);
}

t_room *ft_get_room_from_anthill(t_list *rooms)
{
	if (rooms == NULL)
		return NULL;
	return ((t_room*)(rooms->content));
}

t_room *ft_get_room_from_connected(t_list *connected_rooms)
{
	t_link link;
	t_list *node;
	t_room *room;
	if (connected_rooms == NULL)
		return NULL;
	//return (((t_room*)(*(t_list**)(connected_rooms->content))->content));
	link = *(t_link*)connected_rooms->content;
	node = link.room;
	room = ft_get_room_from_anthill(node);
	return (room);
}

int ft_get_flow_from_connected(t_list *connected_rooms)
{
	t_link link;
	int flow;
	if (connected_rooms == NULL)
		return -1;
	//return (((t_room*)(*(t_list**)(connected_rooms->content))->content));
	link = *(t_link*)connected_rooms->content;
	flow = link.flow;
	return (flow);

}

void ft_print_graf(t_anthill *anthill)
{
	t_list *head;
	t_list *head2;
	head = anthill->rooms;
	while (head)
	{
		printf("Room - %s , level - %d, conected rooms - [", ((t_room*)(head->content))->name, ((t_room*)(head->content))->visited);
		head2 = ((t_room*)(head->content))->connected_rooms;
		while (head2)
		{
			printf("%s - %s flow [%d]\n", ((t_room*)(head->content))->name, ft_get_room_from_connected(head2)->name, ft_get_flow_from_connected(head2));
			/*	if (head2->next)
			{
				printf(", ");
				}*/
			head2 = head2->next;
		}
		printf("\n");
		head = head->next;
	}
}

int ft_map_read(t_anthill *anthill)
{
	char *line;
	
	line = NULL;
	anthill->map = NULL;
	anthill->start_room = NULL;
	anthill->end_room = NULL;
	anthill->rooms = NULL;
	ft_map_read_ants(&line, anthill);
	ft_map_read_rooms(&line, anthill);
   	ft_map_read_links(&line, anthill);
	return (0);
}

void	del(void *content, size_t size)
{
	if (content)
	{
		ft_bzero(content, size);
		ft_memdel(&content);
	}
}

t_list *ft_dequeue(t_list **queue) // внимание выделена паимять под первый элемент
{
	t_list *head;
	
	if (*queue == NULL)
		return (NULL);
	head = *queue;
	*queue = (*queue)->next;
	head->next = NULL;
	return (head);
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
	t_list *top;

	queue = NULL;
	room = ft_get_room_adress(anthill->start_room, anthill); // берём адресок из t_list rooms
	ft_get_room_from_anthill(room)->visited = 0;
	ft_lstp2back(&queue, &room, sizeof(room)); // кладём адресок в очередь
	while (queue) // пока очередь не пуста
	{
		top = ft_dequeue(&queue); // берём из очереди последний элемент вот тут ошибка я беру t_list, а адрес в его контенте
		room = *(t_list**)(top->content); // вот теперь в руме адрес комнаты
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список соседних комнат (список адресов)
		while (rooms)
		{
			if (ft_get_room_from_connected(rooms)->visited == -1)
			{
				ft_get_room_from_connected(rooms)->visited = ft_get_room_from_anthill(room)->visited + 1;
				ft_lstp2back(&queue, &(*(t_list**)(rooms->content)), sizeof(rooms)); 
			}
			rooms = rooms->next;
		}
		ft_lstdelone(&top, del);
	}
	ft_print_graf(anthill);
	//ft_run_ant(anthill);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_anthill anthill;

	ft_map_read(&anthill);
	//ft_print_graf(&anthill);	
	ft_find_path(&anthill);
	(void)argc;
	(void)argv;
}
