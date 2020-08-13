/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:26:59 by majosue           #+#    #+#             */
/*   Updated: 2020/08/13 18:41:02 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_add_path_set(t_anthill *anthill)
{
	t_path_set	new_path_set;
	t_list		*new;

	new_path_set.paths = NULL;
	new_path_set.paths_number = 0;
	new = ft_lstnew(&new_path_set, sizeof(new_path_set));
	if (!new)
		ft_exit(NULL, NULL);
	ft_lstadd(&anthill->path_set, new);
	return (-1);
}

void	ft_add_room_to_path(t_list **path, t_list **room)
{
	t_list *new;

	new = NULL;
	if (!(new = ft_lstnew(&(*room), sizeof(*room))))
		ft_exit(NULL, NULL);
	ft_lstadd(path, new);
}

int		ft_mark_block(t_anthill *anthill, t_list *room)
{
	if (anthill->block == 0)
	{
		ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->\
		disable = 1;
		anthill->block = 1;
	}
	return (1);
}

/*
**	Размечает поток по найденому пути
**	проверяет проверяет нет ли в пути обратных ребер
**	и сохраняет найденые пути кроме обратных
**	расчетное количество линий ухудшается с добавлением
**	нового пути останавливает дальнейшие поиски
*/

void	ft_mark_path_init(int *block, t_list **path)
{
	*block = 0;
	*path = NULL;
}

int		ft_mark_path(t_anthill *anthill)
{
	t_list	*room;
	t_list	*path;
	int		block;

	ft_mark_path_init(&block, &path);
	room = anthill->end_room;
	while (room != anthill->start_room)
	{
		ft_find_link(ft_get_room_from_anthill(room)->from_room, room)->\
		flow += 1;
		ft_find_link(room, ft_get_room_from_anthill(room)->from_room)->\
		flow -= 1;
		if (ft_get_room_from_anthill(room)->exist)
			ft_add_room_to_path(&path, &room);
		if (ft_find_link(ft_get_room_from_anthill(room)->\
		from_room, room)->flow == 0)
			block = ft_mark_block(anthill, room);
		room = ft_get_room_from_anthill(room)->from_room;
	}
	if (block)
	{
		ft_lstdel(&path, del);
		return (1);
	}
	return (ft_add_path_to_set(anthill, path));
}
