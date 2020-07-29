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
	
	while (lst)
	{
		room_adress = *(t_list **)(lst->content);
		room = ft_get_room_from_anthill(room_adress);
		printf("%s", room->name);
		if (room_adress != start && room->used)
		{
		//	printf("room alrady used");
		//	exit(1);
		}
		if (lst->next)
		{
			printf("->");
			room->used = 1;
		}
		lst = lst->next;
	}
}

int		ft_add_path_set(t_anthill *anthill)
{
	t_path_set	new_path_set;
	t_list *new;

	if (anthill->path_set && anthill->path_set->next && anthill->number_lines > ((t_path_set*)(anthill->path_set->next->content))->number_lines)
	{
		anthill->number_lines = ((t_path_set*)(anthill->path_set->next->content))->number_lines;
		//стираем верхний сет
		//не не стираем
		// g
		//решение найдено
		return (0);
	}
	new_path_set.paths = NULL;
	new_path_set.paths_number = 0;
	anthill->number_lines = -1;
	new = ft_lstnew(&new_path_set, sizeof(new_path_set));
	if (!new)
		ft_exit(NULL, NULL);
	ft_lstadd(&anthill->path_set, new);
	//ищем дальше
	return (-1);
	/* if (!ft_lstp2back(&anthill->path_set, &new_path_set, sizeof(new_path_set)))
		ft_exit(NULL, NULL); */
}

int	ft_add_path_to_set(t_anthill *anthill, t_list **path)
{
	t_path	new_path;
	t_list *path_set;

	
	
	//-------------заполнили новый path----------
	new_path.path = NULL;
	
	ft_lstp2back(&new_path.path, path, sizeof *path); 
	new_path.path_len = ft_get_room_from_anthill(anthill->end_room)->visited / 2 + 1;
	new_path.path_capacity = 0;
	new_path.path_flow = 0;
	
	if (!anthill->path_set)
		ft_add_path_set(anthill);
	path_set = anthill->path_set;
	((t_path_set*)(path_set->content))->number_lines = ft_find_nbr_lines(anthill, ((t_path_set*)(path_set->content))->paths_number, new_path.path_len);
	if (anthill->number_lines == -1 || anthill->number_lines >= ((t_path_set*)(path_set->content))->number_lines) // если поставить >= он продолжит искать и найдет оптимальней чем просит карта из генератора
			anthill->number_lines =  ((t_path_set*)(path_set->content))->number_lines;
		else
		{
			// сравниваем с количеством линий на предидущем наборе
			// Если этот набор хуже, удаляем его.
			// оставляем наверху старый.
			// подчищаем patth
			return(0);
		}
	ft_lstp2back(&((t_path_set*)(path_set->content))->paths, &new_path, sizeof new_path);
	((t_path_set*)(path_set->content))->paths_number++;
	return (1);
}

void ft_add_room_to_path(t_list** path, t_list** room)
{
	t_list *new;

	new = NULL;
	if (!(new = ft_lstnew(room, sizeof(*room))))
		ft_exit(NULL, NULL);
	ft_lstadd(path, new);
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
		ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->flow -= 1;
		if (ft_get_room_from_anthill(room)->exist)
			ft_add_room_to_path(&path, &room);
		if (ft_find_link(ft_get_room_from_anthill(room)->from_room, room)->flow == 0)
		{
			ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->disable = 1;
			ft_lstdel(&path, del);
			// вот тут надо считать количество линий, заполнять емкости путей
			// сравнивать с предидущими
			return (ft_add_path_set(anthill));
		}
		room = ft_get_room_from_anthill(room)->from_room;
	}
	ft_add_room_to_path(&path, &room); // добавляет стартовую комнату. Оно нам надо?
	return (ft_add_path_to_set(anthill, &path));
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

int ft_get_rest_ants(t_anthill *anthill, int ants, int last_used_path, int last_path_len)
{
	int i;
	int a;
	t_list *path;

	path = ((t_path_set*)(anthill->path_set->content))->paths;
	a = ants - 1;
	i = 0;
	while (i < last_used_path)
	{
		a = a - 1 - (last_path_len - ((t_path*)(path->content))->path_len);
		if (a <= 0)
			return (0);
		i++;
		path = path->next;
	}	
	return (a);
}

int ft_get_last_used_path_len(t_anthill *anthill, int last_used_path) // это не понадобится
{
	int i;
	t_list *path;

	path = ((t_path_set*)(anthill->path_set->content))->paths;
	i = 0;
	while (i < last_used_path)
	{
		i++;
		path = path->next;
	}
	return (((t_path*)(path->content))->path_len);
}

int ft_find_nbr_lines(t_anthill *anthill, int last_used_path, int last_used_path_len)
{
	int rest_ants;
	int rest_ants2;
	int nbr_lines;

	rest_ants = ft_get_rest_ants(anthill, anthill->ants, last_used_path, last_used_path_len);
	rest_ants2 = (rest_ants % (last_used_path + 1)) == 0 ? 0 : 1;
	nbr_lines = last_used_path_len + rest_ants / (last_used_path + 1) + rest_ants2;
	return (nbr_lines);
}

int ft_find_optimal_nbr_lines(t_anthill *anthill) // это в адд ту патсет будет делаться.
{
	int i;
	int number_lines;
	int current_nbr_lines;
	t_list *set;

	i = 0;
	set = anthill->path_set;
	number_lines = -1;
	while (i < ((t_path_set*)(set->content))->paths_number)
	{
		current_nbr_lines = ft_find_nbr_lines(anthill, i, 1);
		if (number_lines == -1 || number_lines > current_nbr_lines) // если поставить >= он продолжит искать и найдет оптимальней чем просит карта из генератора
			number_lines = current_nbr_lines;
		else
			break;
		i++;
	}
	return (number_lines);
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
	/* 	if (max_flow == anthill->ants) //возможная оптимизация
			break; */
	}
	anthill->start_room = start;

	/* ----------------вывод карты----------------- */
	paths = anthill->map;
	char *line;
	line = "";
	//int len = 0;
	while (paths)
	{
		
		/* len = ft_strlen((char*)(paths->content));
		write(1, (char*)(paths->content), len);
		write(1, "\n", 1); */
		printf("%s\n", (char*)(paths->content));
		/* line = ft_strjoin(line,(char*)(paths->content));
		line = ft_strjoin(line,"\n"); */
		paths = paths->next;
	}

	/* ----------------вывод путей----------------- */
	printf("#Maxflow = %d\n", max_flow);
	t_list *path;
	int i = 0;
	//int lines = 0;
	//int ants = anthill->ants;
	t_list *set =  anthill->path_set;
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
	//printf("Optimal number lines - %d", ft_find_optimal_nbr_lines(anthill));
	printf("Optimal number lines - %d", anthill->number_lines);

	return (1);
}