/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/07/19 13:19:10 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	ft_map_read(t_anthill *anthill)
{
	char *line;
	
	line = NULL;
	anthill->map = NULL;
	anthill->start_room = NULL;
	anthill->end_room = NULL;
	anthill->rooms = NULL;
	anthill->path_set = NULL;
	anthill->paths_set_number = 0;
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
 //ft_print_graf(&anthill);
}
