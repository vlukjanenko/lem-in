/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/08/12 21:49:43 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

//временно для оценки скорости работы частей
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
//-------------------------------------------

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

int	main(void)
{
	t_anthill anthill;

	start_time = time(NULL);
	ft_map_read(&anthill);
	ft_find_path(&anthill);
	point[2] = passed_time();
	ft_print_map(&anthill);
	ft_select_optimal_path_set(&anthill);
	ft_print_selected_paths(((t_path_set*)(anthill.path_set->content))->paths);
	ft_printf("##Optimal number lines  %d\n", anthill.number_lines);
	ft_run_ants(&anthill);
	point[3] = passed_time();
	ft_printf("Map read rooms take %3.1fs\n", point[0]);
	ft_printf("Map read links take %3.1fs\n", point[1]);
	ft_printf("Algo run take %3.1fs\n", point[2]);
	ft_printf("Output take %3.1fs\n", point[3]);
	ft_free_anthill(&anthill);
	return(EXIT_SUCCESS);
}
