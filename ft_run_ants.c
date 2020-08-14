/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:34:02 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 07:01:04 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Shift ants that already in path;
*/

void	ft_shift_ants(t_list *path)
{
	t_list *room;
	t_list *next_room;

	if (path->next)
	{
		room = *(t_list **)(path->content);
		next_room = *(t_list **)(path->next->content);
		ft_get_room_from_anthill(next_room)->ant =\
		ft_get_room_from_anthill(room)->ant;
		ft_get_room_from_anthill(room)->ant = NULL;
		if (ft_get_room_from_anthill(next_room)->ant)
		{
			ft_printf("%s-%s ", ft_get_room_from_anthill(next_room)->ant,\
			ft_get_room_from_anthill(next_room)->name);
		}
	}
	else if (path)
	{
		room = *(t_list **)(path->content);
		if (ft_get_room_from_anthill(room)->ant)
		{
			ft_strdel(&ft_get_room_from_anthill(room)->ant);
		}
	}
}

/*
**	Add new ant in path
*/

void	ft_put_ant_to_path(t_list *path, int *j)
{
	char	*index;
	char	*ant_name;
	t_list	*room;
	t_list	*path_body;
	t_path	*path_header;

	path_header = (t_path *)(path->content);
	path_header->path_flow++;
	path_body = path_header->path;
	if (!(index = ft_itoa(*j)))
		ft_exit(NULL, NULL);
	if (!(ant_name = ft_strjoin("L", index)))
		ft_exit(NULL, NULL);
	free(index);
	ft_lstiter(path_body, ft_shift_ants);
	room = *(t_list **)(path_body->content);
	ft_get_room_from_anthill(room)->ant = ant_name;
	ft_printf("%s-%s ", ft_get_room_from_anthill(room)->ant,\
	ft_get_room_from_anthill(room)->name);
}

/*
**	Put new ants and shift ants over all selected paths
*/

void	ft_push_ants(t_anthill *anthill, int *j)
{
	t_list *path;
	t_path *p;

	path = ((t_path_set *)(anthill->path_set->content))->paths;
	while (path)
	{
		p = (t_path *)(path->content);
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

/*
**	Run ft_push_ants anthill->number_lines times
*/

void	ft_run_ants(t_anthill *anthill)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < anthill->number_lines)
	{
		ft_push_ants(anthill, &j);
		i++;
		ft_printf("\n");
	}
}
