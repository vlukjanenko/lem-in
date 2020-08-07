/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:18:06 by majosue           #+#    #+#             */
/*   Updated: 2020/08/02 01:51:10 by majosue          ###   ########.fr       */
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

int		ft_add_path_set(t_anthill *anthill)
{
	t_path_set	new_path_set;
	t_list *new;
	printf("LL%d\n",anthill->number_lines);
	new_path_set.paths = NULL;
	new_path_set.paths_number = 0;
	new_path_set.optimal = 0;
	new = ft_lstnew(&new_path_set, sizeof(new_path_set));
	if (!new)
		ft_exit(NULL, NULL);
	ft_lstadd(&anthill->path_set, new);
	return (-1);
}

int		ft_get_lastpath_len(t_anthill *anthill)
{
	t_list *path;
	t_path_set	*paths;


	paths = (t_path_set*)(anthill->path_set->content);
	path = paths->paths;
	while (path->next)
	{
		path = path->next;
	}
	return(((t_path*)(path->content))->path_len);
}

void	ft_del_last_path_from_set(t_anthill *anthill)
{
	t_path_set *ps;
	t_list *path;
	t_list *prev_path;
	
	ps = (t_path_set*)(anthill->path_set->content);
	path = ps->paths;
	while (path->next)
	{
		prev_path = path;
		path = path->next;
	}
	ft_lstdelone(&path, del_path);
	prev_path->next = NULL;
	ps->paths_number--;
}

t_path	ft_new_path_init(t_anthill *anthill, t_list *path)
{
	t_path	new_path;

	if (!anthill->path_set)
		ft_add_path_set(anthill);
	new_path.path = NULL;
	new_path.path = path;
	new_path.path_capacity = 0;
	new_path.path_flow = 0;
	new_path.ants_in_path = 0;
	new_path.path_len = ft_get_room_from_anthill(anthill->end_room)->visited / 2 + 1;
	return (new_path);
}

void ft_roll_back_to_optimal(t_anthill *anthill)
{
	int len;
	t_path_set *ps;
	
	ps = anthill->path_set->content;
	ft_del_last_path_from_set(anthill);
	len = ft_get_lastpath_len(anthill);
	ps->optimal = 1;
	ps->number_lines = ft_find_nbr_lines(anthill, ps->paths_number, len);
}

int	ft_add_path_to_set(t_anthill *anthill, t_list *path)
{
	t_path		new_path;
	t_path_set	*ps;

	new_path = ft_new_path_init(anthill, path);
	ps = (t_path_set*)(anthill->path_set->content);
	if (ps->optimal)
		return(1);
	if (!(ft_lstp2back(&ps->paths, &new_path, sizeof new_path)))
		ft_exit(NULL, NULL);
	ps->paths_number++;
	ps->number_lines = ft_find_nbr_lines(anthill, ps->paths_number, new_path.path_len);
	if (anthill->number_lines == -1 || anthill->number_lines >= ps->number_lines) 
		anthill->number_lines = ps->number_lines;
	else
		ft_roll_back_to_optimal(anthill);
	return (1);
}

void ft_add_room_to_path(t_list** path, t_list *room)
{
	t_list *new;

	new = NULL;
	if (!(new = ft_lstnew(&room, sizeof(room))))
		ft_exit(NULL, NULL);
	ft_lstadd(path, new);
}

/*
**	Размечает поток по найденому пути
**	проверяет проверяет нет ли в пути обратных ребер
**	и сохраняет найденые пути если не нашла обратных
**	расчетное количество линий ухудшается с добавлением
**	нового пути останавливает дальнейшие поиски
*/

int ft_mark_path(t_anthill *anthill)
{
	t_list *room;
	t_list *path;
	int block;

	block = 0;
	path = NULL;
	room = anthill->end_room;
	while (room != anthill->start_room)
	{
		ft_find_link(ft_get_room_from_anthill(room)->from_room, room)->flow += 1;
		ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->flow -= 1;
		if (ft_get_room_from_anthill(room)->exist)
		{
			ft_add_room_to_path(&path, room);
		}
		if (ft_find_link(ft_get_room_from_anthill(room)->from_room, room)->flow == 0)
		{
			block = 1;
			if (anthill->block == 0)
			{
				ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->disable = 1;
				anthill->block = 1;
			}
		}
		room = ft_get_room_from_anthill(room)->from_room;
	}
	if (block)
	{
		ft_lstdel(&path, del);
		anthill->block = 1;
		return (1);
	}
	return (ft_add_path_to_set(anthill, path));
}

/*
**	Поиск дополнительного пути
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

/* int ft_get_number_links(t_list *lst)
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
 */
/*
**	Распределяем начальное количество муравьёв по путям
**	в каждый путь по 1 муравью + разницу длин последнего и текущего
**	возвращаем остаток нераспределенных муравьев
*/


int ft_get_rest_ants(t_anthill *anthill, int ants, int last_path_len)
{
	int a;
	t_list *path;

	path = ((t_path_set*)(anthill->path_set->content))->paths;
	a = ants;
	while (path)
	{
		a = a - 1 - (last_path_len - ((t_path*)(path->content))->path_len);
		((t_path*)(path->content))->path_capacity = 1 + (last_path_len - ((t_path*)(path->content))->path_len);
		if (a < 0)
			 a = 0;
		path = path->next;
	}
	return (a);
}

void ft_reditrub_ants(t_anthill *anthill, int number_paths, int rest_ants)
{
	t_list *paths;
	int each_path_addon;
	int rest;
	
	paths = ((t_path_set*)(anthill->path_set->content))->paths;
	each_path_addon	= rest_ants / number_paths;
	rest = rest_ants % number_paths;
	while (paths)
	{
		((t_path*)(paths->content))->path_capacity += each_path_addon + ((rest > 0) ? 1 : 0);
		rest--;
		paths = paths->next;
	}
}

int ft_find_nbr_lines(t_anthill *anthill, int paths_number, int last_used_path_len)
{
	int rest_ants; 
	int rest_ants2;
	int nbr_lines;

	rest_ants = ft_get_rest_ants(anthill, anthill->ants, last_used_path_len);
	ft_reditrub_ants(anthill, paths_number, rest_ants);
	rest_ants2 = (rest_ants % paths_number) == 0 ? 0 : 1;
	nbr_lines = last_used_path_len + rest_ants / paths_number + rest_ants2;
	return (nbr_lines);
}

int ft_find_optimal_path_set_position(t_anthill *anthill)
{
	t_list *psets;
	t_path_set *ps;
	int i;
	int position;
	
	position = 0;
	i = 0;
	anthill->number_lines = -1;
	psets = anthill->path_set;
	while (psets)
	{
		ps = (t_path_set*)(psets->content);
		if (anthill->number_lines == -1 || anthill->number_lines > ps->number_lines)
		{
			anthill->number_lines = ps->number_lines;
			position = i;
		}
		i++;
		psets = psets->next;
	}
	return (position);
}

void	ft_select_optimal_path_set(t_anthill *anthill) // вои эту переделать чтоб искала по всем сетам
{
	t_list *set;
	int n;
	int i;
	

	if (!anthill->path_set)
	{
		// чистка?
		ft_exit("Error: No path found from start to end\n", NULL);
	}
	i = 0;
	n = ft_find_optimal_path_set_position(anthill);
	while (i < n)
	{
		set = anthill->path_set->next;
		ft_lstdelone(&anthill->path_set, del_pathset); 
		anthill->path_set = set;
		i++;
	}
}

void ft_print_map(t_anthill *anthill)
{
	t_list *map;	
	int len;
	
	map = anthill->map;
	while (map)
	{
		len = ft_strlen((char*)(map->content));
		write(1, (char*)(map->content), len);
		write(1, "\n", 1);
		map = map->next;
	}
}

void ft_shift_ants(t_list *path)
{
	t_list *room;
	t_list *next_room;
	
	if (path->next)
	{
		room = *(t_list**)(path->content);
		next_room = *(t_list**)(path->next->content);
		ft_get_room_from_anthill(next_room)->ant = ft_get_room_from_anthill(room)->ant;
		ft_get_room_from_anthill(room)->ant = NULL;
		if (ft_get_room_from_anthill(next_room)->ant)
		{		
			printf("%s-%s ", ft_get_room_from_anthill(next_room)->ant, ft_get_room_from_anthill(next_room)->name);
		}
	}
	else if (path)
	{
		room = *(t_list**)(path->content);
		if (ft_get_room_from_anthill(room)->ant)
		{
			ft_strclr(ft_get_room_from_anthill(room)->ant);
			free(ft_get_room_from_anthill(room)->ant);
			ft_get_room_from_anthill(room)->ant = NULL;
			//ft_strdel(&ft_get_room_from_anthill(room)->ant);

		}
	}
}

void ft_put_ant_to_path(t_list *path, int *j)
{
	char* index;
	char* ant_name;
	t_list *room;
	t_list *path_body;
	t_path *path_header;

	path_header = (t_path*)(path->content);
	path_header->path_flow++ ;
	path_body = path_header->path;
	if (!(index = ft_itoa(*j)))
		ft_exit(NULL, NULL);
	if (!(ant_name = ft_strjoin("L", index)))
		ft_exit(NULL, NULL);
	free(index);
	ft_lstiter(path_body, ft_shift_ants);
	room = *(t_list**)(path_body->content);
	ft_get_room_from_anthill(room)->ant = ant_name;
	printf("%s-%s ", ft_get_room_from_anthill(room)->ant, ft_get_room_from_anthill(room)->name);
}

void ft_push_ants(t_anthill *anthill, int *j)
{
	t_list *path;
	t_path* p;
	
	path = ((t_path_set*)(anthill->path_set->content))->paths;
	while (path)
	{
		p = (t_path*)(path->content);
		if (p->path_capacity > p->path_flow && (*j) <= anthill->ants)
			{	
				ft_put_ant_to_path(path, j);
				(*j)++;
			}
		else
			ft_lstiter(p->path, ft_shift_ants);
		path = path->next;
	}
}

void ft_run_ants(t_anthill *anthill)
{
	int i;
	int j;
	
	i = 0; // индекс линий
	j = 1; // индекс муравья 
	while (i < anthill->number_lines)
	{
		ft_push_ants(anthill, &j);
		i++;
		printf("\n");
	}
}

void ft_print_selected_paths(t_list *paths)
{
	t_list *path;

	while (paths)
	{
		path = ((t_path*)(paths->content))->path;
		printf("##path ");
		while (path)
		{
			printf("%s", ((t_room*)((*(t_list**)(path->content))->content))->name);
			if (path->next)
				printf("->");
			path = path->next;
		}
		printf("\n");
		paths = paths->next;
	}
}

int ft_karp(t_anthill *anthill)
{
	int result;
	t_list *start;

	start = anthill->start_room;
	anthill->start_room = anthill->start_room->next;
	ft_lstiter(anthill->rooms, ft_reset_visited);
	while (1)
	{
		result = ft_find_augmenting_path(anthill); // посиск добваочного пути
		if (result == 1)
			ft_lstiter(anthill->rooms, ft_reset_visited); // сброс посещенных комнат
		else if (result == 0 && anthill->block == 1)
		{
			ft_add_path_set(anthill);
			ft_reset_flows(anthill); // сброс потоков
			ft_lstiter(anthill->rooms, ft_reset_visited); // сброс посещенных комнат
			anthill->number_lines = -1; 
			anthill->block = 0;	
		}
		else
			break;
	}
	anthill->start_room = start;

	ft_print_map(anthill);
	ft_select_optimal_path_set(anthill);
	ft_print_selected_paths(((t_path_set*)(anthill->path_set->content))->paths);
	printf("##Optimal number lines  %d\n", anthill->number_lines);
	ft_run_ants(anthill);
	return (1);
}