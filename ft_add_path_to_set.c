/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_path_to_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:43:22 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 06:59:14 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_get_lastpath_len(t_anthill *anthill)
{
	t_list		*path;
	t_path_set	*paths;

	paths = (t_path_set *)(anthill->path_set->content);
	path = paths->paths;
	while (path->next)
	{
		path = path->next;
	}
	return (((t_path *)(path->content))->path_len);
}

void	ft_del_last_path_from_set(t_anthill *anthill)
{
	t_path_set	*ps;
	t_list		*path;
	t_list		*prev_path;

	ps = (t_path_set *)(anthill->path_set->content);
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
	t_path new_path;

	if (!anthill->path_set)
		ft_add_path_set(anthill);
	new_path.path = NULL;
	new_path.path = path;
	new_path.path_capacity = 0;
	new_path.path_flow = 0;
	new_path.path_len =\
	ft_get_room_from_anthill(anthill->end_room)->visited / 2 + 1;
	return (new_path);
}

void	ft_roll_back_to_optimal(t_anthill *anthill)
{
	int			len;
	t_path_set	*ps;

	ps = anthill->path_set->content;
	ft_del_last_path_from_set(anthill);
	len = ft_get_lastpath_len(anthill);
	ps->number_lines = ft_find_nbr_lines(anthill, ps->paths_number, len);
}

int		ft_add_path_to_set(t_anthill *anthill, t_list *path)
{
	t_path		new_path;
	t_path_set	*ps;

	new_path = ft_new_path_init(anthill, path);
	ps = (t_path_set *)(anthill->path_set->content);
	if (!(ft_lstp2back(&ps->paths, &new_path, sizeof(new_path))))
		ft_exit(NULL, NULL);
	ps->paths_number++;
	ps->number_lines =\
	ft_find_nbr_lines(anthill, ps->paths_number, new_path.path_len);
	if (anthill->number_lines == -1 ||\
	anthill->number_lines >= ps->number_lines)
		anthill->number_lines = ps->number_lines;
	else
	{
		ft_roll_back_to_optimal(anthill);
		return (0);
	}
	return (1);
}
