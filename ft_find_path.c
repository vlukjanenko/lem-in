/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:18:06 by majosue           #+#    #+#             */
/*   Updated: 2020/07/23 07:58:35 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/* Выкинуть!!! Функция для распечатки графа */

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

/*
**	Get pointer from anthill->rooms to t_room structure
*/

t_room *ft_get_room_from_anthill(t_list *rooms)
{
	if (rooms == NULL)
		return NULL;
	return ((t_room *)(rooms->content));
}

/*
**	Get pointer from connected_rooms->content to anthil->rooms
*/

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

/*
**	Get pointer connected_rooms->content
*/

t_link *ft_get_link_from_connected(t_list *connected_rooms)

{
	t_link *link;
	if (connected_rooms == NULL)
		return NULL;
	link = (t_link *)connected_rooms->content;
	return (link);
}

/*
**	Get pointer from anthill->connected_rooms to t_room structure
*/

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

/*
**	Находит соответствующий link
*/

t_link *ft_find_link(t_list *node, t_list *connected_room)
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

/* Выкинуть!!! Печатает путь. */

void ft_print_path(t_list *lst, t_list *start)
{
	t_list *room_adress;
	t_room *room;
	int i;

	i = 0;
	while (lst)
	{
		room_adress = *(t_list **)(lst->content);
		room = ft_get_room_from_anthill(room_adress);
		if (i % 2)
			printf("%s", room->name);
		if (room_adress != start && room->used)
		{
		//	printf("room alrady used");
		//	exit(1);
		}
		if (lst->next && i % 2)
		{
			printf("->");
			room->used = 1;
		}
		i++;
		lst = lst->next;
	}
}

void	ft_add_path_set(t_anthill *anthill)
{
	t_path_set	new_path_set;
	
	new_path_set.paths = NULL;
	new_path_set.paths_number = 0;
	if (!ft_lstp2back(&anthill->path_set, &new_path_set, sizeof(new_path_set)))
		ft_exit(NULL, NULL);
}

void	ft_add_path_to_set(t_anthill *anthill, t_list **path)
{
	t_path	new_path;
	t_list *path_set;

	//-------------заполнили новый path----------
	new_path.path = NULL;
	ft_lstp2back(&new_path.path, path, sizeof *path);
	new_path.path_len = ft_get_room_from_anthill(anthill->end_room)->visited / 2 + 1;
	
	path_set = anthill->path_set;
	while(path_set->next)
	{
		path_set = path_set->next; //спустились к последнему сету
	}
	ft_lstp2back(&((t_path_set*)(path_set->content))->paths, &new_path, sizeof new_path);
	((t_path_set*)(path_set->content))->paths_number++;
}

/*
**	Размечает поток по найденому пути
**	проверяет проверяет нет ли в пути обратных ребер
**	и сохраняет найденые пути если не нашла обратных
*/

int ft_mark_path(t_anthill *anthill)
{
	t_list *room;
	t_list *path;

	path = NULL;
	room = anthill->end_room;
	while (room != anthill->start_room)
	{
		ft_find_link(ft_get_room_from_anthill(room)->from_room, room)->flow += 1;
		if (ft_find_link(room, ft_get_room_from_anthill(room)->from_room))
		{
			ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->flow -= 1;
		}
		ft_lstadd(&path, ft_lstnew(&room, sizeof(room))); // будет падать если не отработает ft_lstnew
		if (ft_find_link(ft_get_room_from_anthill(room)->from_room, room)->flow == 0)
		{
			ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->disable = 1;
			/* вот тут надо дополнитель чистить пути. А может не просто вычищать а сохранять. 
					Если мало муравьёв все непересекающиенся пути не нужны? Нужны Кратчайшие? Надо подумать
					так же в ft_get_room_from_anthill(end_room)->visited лежит длинна пути. Её тоже надо сохранять */
			//ft_lstdel(&anthill->paths, del);
			ft_lstdel(&path, del);
			ft_add_path_set(anthill);
			return (-1);
		}
		room = ft_get_room_from_anthill(room)->from_room;
	}
	ft_lstadd(&path, ft_lstnew(&room, sizeof(room))); // добавляет стартовую комнату. Оно нам не надо!
	if (anthill->path_set == NULL)
		ft_add_path_set(anthill);
	ft_add_path_to_set(anthill, &path);
	//ft_lstp2back(&anthill->path_set->, &path, sizeof(path));
	return (1);
}

/*
**	Поиск увеличивающего пути
*/

int ft_find_augmenting_path(t_anthill *anthill)
{
	t_list *queue;
	t_list *room;
	t_list *rooms;

	queue = NULL;
	ft_get_room_from_anthill(anthill->start_room)->visited = 0;
	ft_lstp2back(&queue, &anthill->start_room, sizeof(room)); // кладём адресок в очередь
	while (queue)											  // пока очередь не пуста
	{
		room = ft_dequeue(&queue);								 // берем адрес комнаты из очереди
		rooms = ft_get_room_from_anthill(room)->connected_rooms; // получаем список адресов соседних комнат
		while (rooms)
		{
			if (ft_get_room_from_connected(rooms)->visited == -1 &&
				ft_get_link_from_connected(rooms)->capacity - ft_get_link_from_connected(rooms)->flow == 1 &&
				ft_get_link_from_connected(rooms)->disable == 0)
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
	ft_get_room_from_anthill(lst)->visited = -1;
	ft_get_room_from_anthill(lst)->from_room = NULL;
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
	int result;
	t_list *paths;
	t_list *start;

	start = anthill->start_room;
	anthill->start_room = anthill->start_room->next;
	ft_lstiter(anthill->rooms, ft_reset_visited);
	max_flow = 0;
	while (1)
	{
		result = ft_find_augmenting_path(anthill);
		if (result == -1) // если нашли обратные ребра в найденом пути
		{
			ft_reset_flows(anthill); // сброс потоков
			ft_lstiter(anthill->rooms, ft_reset_visited); // сброс посещенных комнат
			max_flow = 0; 
		}
		else if (result == 1)
		{
			max_flow++; // предположительно тут надо отслеживать зависимость от количества муравьёв, количество путей, длины путей?
			ft_lstiter(anthill->rooms, ft_reset_visited);
		}
		
		else
			break; //выходим когда путей уже нет.
	/* 	if (max_flow == anthill->ants)
			break; */
	}
	/* ----------------вывод карты----------------- */
	paths = anthill->map;
	while (paths)
	{
		printf("%s\n", (char*)(paths->content));
		paths = paths->next;
	}
	/* ----------------вывод путей----------------- */
	printf("#Maxflow = %d\n", max_flow);
	/* paths = anthill->paths;
	while (paths)
	{
		printf("##path\n");
		printf("%s->", ft_get_room_from_anthill(start)->name);
		ft_print_path(*(t_list **)(paths->content), anthill->start_room);
		printf("\n");
		paths = paths->next;
	}
	*/
	/* ----------------------------------------------*/ 
	t_list *set = anthill->path_set;
	t_list *path;
	int i = 0;
	//int lines = 0;
	//int ants = anthill->ants;
	while (set)
	{
		printf("Pathset = %d\n", i);
		path = ((t_path_set*)(set->content))->paths;
		int firstpath = ((t_path*)(path->content))->path_len;
		printf("first path len %d\n", firstpath);
		while (path)
		{
			printf("##path\n");
			ft_print_path(*(t_list **)((((t_path*)(path->content))->path)->content), anthill->start_room);			
			printf("\n");
			path = path->next;
		}
		i++;
		set = set->next;
	}


	return (1);
}