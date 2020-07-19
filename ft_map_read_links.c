/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 09:05:08 by majosue           #+#    #+#             */
/*   Updated: 2020/07/19 12:36:54 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void ft_set_edge(t_list *in_room, t_list *out_room, int flow, int capacity)
{
	t_link edge;
	edge.room = out_room;
	edge.flow = flow;
	edge.capacity = capacity;
	edge.disable = 0;
	if (!ft_lstp2back(&((t_room*)(in_room->content))->connected_rooms, &edge, sizeof(edge)))
		ft_exit(NULL, NULL);
}

int ft_is_link(char *line, t_anthill *anthill)
{
	char **room_names;
    t_list *room = NULL;
    t_list *connected_room = NULL;
//	t_link edge;

    if ((room_names = ft_strsplit(line, '-')) == NULL)
        ft_exit(NULL, NULL);
   
	if (ft_array_len(room_names) != 2)
    {
       //нужно ли чистить? ft_clean_array(&room_names);
        ft_exit("Error: Invalid line in map: ", line);
    }
   //  printf("%s - %s\n", room_names[0], room_names[1]);
    if ((room = ft_get_room_adress(room_names[0], anthill)) == NULL ||\
    (connected_room = ft_get_room_adress(room_names[1], anthill)) == NULL)
        ft_exit("Error: unknown room: ", line);
	/* ft_set_edge(room, connected_room);
	ft_set_edge(connected_room, room); */
	/* if (ft_find_link(room->next, connected_room) || ft_find_link(connected_room->next, room))
	{
		printf("repeated link");
		exit(1);
	} */
	ft_set_edge(room->next, connected_room, 0, 1);
	ft_set_edge(connected_room, room->next, 0, 0);
	ft_set_edge(connected_room->next, room, 0, 1);
	ft_set_edge(room, connected_room->next, 0, 0);
   // printf("%p - %p\n", room, connected_room);
   // printf("%s - %s\n", ((t_room*)(room->content))->name, ((t_room*)(connected_room->content))->name);
	if (!ft_lstp2back(&anthill->map, line, ft_strlen(line) + 1))//тупо для карты чтоб вывести наверно не нужно
		ft_exit(NULL, NULL);

    return (EXIT_SUCCESS);
}

int ft_map_read_links(char **line,  t_anthill *anthill) // сюда приходит с заполненым лайном надо сразу чекать что там лежит
{
    int read_state;

    ft_is_link(*line, anthill);
    free(*line);
	while ((read_state = get_next_line(0, line)) > 0)
	{
		if (ft_is_comment(*line, &anthill->map) == 0 ||
			ft_is_command(*line, &anthill->map) == 0 ||
			ft_is_link(*line, anthill) == 0)
		{
			free(*line);
			continue;
		}
		break ;
	}
	if (read_state == -1)
		ft_exit(NULL, NULL);
    if (read_state > 0)
		ft_exit("Error: invalid line in map", "");
    return (EXIT_SUCCESS);
}