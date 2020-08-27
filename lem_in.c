/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/08/27 16:45:07 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_optimal_path_set_position(t_anthill *anthill)
{
	t_list		*psets;
	t_path_set	*ps;
	int			i;
	int			position;

	position = 0;
	i = 0;
	anthill->number_lines = -1;
	psets = anthill->path_set;
	while (psets)
	{
		ps = (t_path_set *)(psets->content);
		if (anthill->number_lines == -1 ||
			anthill->number_lines > ps->number_lines)
		{
			anthill->number_lines = ps->number_lines;
			position = i;
		}
		i++;
		psets = psets->next;
	}
	return (position);
}

/*
**	Remove path_set until optimal stay first
*/

void	ft_select_optimal_path_set(t_anthill *anthill)
{
	t_list	*set;
	int		n;
	int		i;

	if (!anthill->path_set)
	{
		ft_exit("ERROR: No path found from start to end\n", NULL);
	}
	i = 0;
	n = ft_find_optimal_path_set_position(anthill);
	while (i < n)
	{
		set = anthill->path_set;
		anthill->path_set = anthill->path_set->next;
		set->next = NULL;
		ft_lstdel(&set, del_pathset);
		i++;
	}
}

int		ft_map_read(t_anthill *anthill)
{
	char *line;

	line = NULL;
	anthill->map = NULL;
	anthill->start_room = NULL;
	anthill->end_room = NULL;
	anthill->rooms = NULL;
	anthill->path_set = NULL;
	anthill->number_lines = -1;
	anthill->block = 0;
	ft_map_read_ants(&line, anthill);
	ft_map_read_rooms(&line, anthill);
	ft_map_read_links(&line, anthill);
	return (EXIT_SUCCESS);
}

void	ft_print_map(t_list *lst)
{
	ft_printf("%s\n", (char*)(lst->content));
}

int		main(void)
{
	t_anthill anthill;
	ft_map_read(&anthill);
	ft_find_path(&anthill);
	ft_lstiter(anthill.map, ft_print_map);
	ft_printf("\n");
	ft_select_optimal_path_set(&anthill);
	ft_run_ants(&anthill);
	ft_free_anthill(&anthill);
	return (EXIT_SUCCESS);
}
