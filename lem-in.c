/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/08/10 18:43:48 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

time_t start_time;
double point[4];

double passed_time()
{
	time_t now;
	double dif;
	now = time(NULL);
	dif = difftime(now, start_time);
	start_time = now;
	return (dif);
}

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
		if (((t_room*)(content))->ant)
			free(((t_room*)(content))->ant);
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
	anthill->block = 0;
	ft_map_read_ants(&line, anthill);
	ft_map_read_rooms(&line, anthill);
	point[0] = passed_time();
   	ft_map_read_links(&line, anthill);
	point[1] = passed_time();
	return (EXIT_SUCCESS);
}

void test_del_path(t_anthill *anthill)
{
	t_path_set *path;
	t_path *path_head;
	t_list *p;
	t_list *ph;

	path = (t_path_set*)(anthill->path_set->content);
	ph = path->paths;
	while (path)
	{
		ph = path->paths;
	}
	path_head = (t_path*)(path->paths->content);
	p = path_head->path;
	ft_lstdel(&p, del);
	ft_lstdel(&path->paths, del);
	ft_lstdel(&anthill->path_set, del);

}

int	main(int argc, char **argv)
{
	t_anthill anthill;

	start_time = time(NULL);
	(void)argc;
	(void)argv;
	ft_map_read(&anthill);
	ft_karp(&anthill);
	point[2] = passed_time();
	ft_printf("Map read rooms take %3.1fs\n", point[0]);
	ft_printf("Map read links take %3.1fs\n", point[1]);
	ft_printf("Algo run take %3.1fs\n", point[2]);
	//test_del_path(&anthill);
	ft_free_antchill(&anthill);
}
