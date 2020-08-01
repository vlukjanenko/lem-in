/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/07/31 20:46:05 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


void	del_path(void *content, size_t size)
{
	if (content)
	{
		ft_lstdel(&((t_path*)(content))->path, del);
		ft_bzero(content, size);
		ft_memdel(&content);
	}
}

void	del_pathset(void *content, size_t size)
{
	if (content)
	{
		ft_lstdel(&((t_path_set*)(content))->paths, del_path);
		ft_bzero(content, size);
		ft_memdel(&content);
	}
}

void	del_room(void *content, size_t size)
{
	if (content)
	{
		ft_strclr(((t_room*)(content))->name);
		ft_strdel(&((t_room*)(content))->name);
		ft_lstdel(&((t_room*)(content))->connected_rooms, del);
		ft_bzero(content, size);
		ft_memdel(&content);
	}
}


void	ft_free_antchill(t_anthill *anthill)
{
	if (anthill->map)
		ft_lstdel(&(anthill->map), del);
	if (anthill->rooms)
		ft_lstdel(&(anthill->rooms), del_room);
	if (anthill->path_set)
		ft_lstdel(&(anthill->path_set), del_pathset);
}

int	ft_map_read(t_anthill *anthill)
{
	char *line;
	
	line = NULL;
	anthill->map = NULL;
	anthill->start_room = NULL;
	anthill->end_room = NULL;
	anthill->rooms = NULL;
	anthill->path_set = NULL;
	anthill->number_lines = -1;
	ft_map_read_ants(&line, anthill);
	ft_map_read_rooms(&line, anthill);
   	ft_map_read_links(&line, anthill);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_anthill anthill;

	(void)argc;
	(void)argv;
	ft_map_read(&anthill);
//	ft_print_graf(&anthill);
	//ft_find_path(&anthill);	
	ft_karp(&anthill);
	ft_free_antchill(&anthill);
//ft_print_graf(&anthill);
}
