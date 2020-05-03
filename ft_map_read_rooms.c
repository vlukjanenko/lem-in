/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 18:23:10 by majosue           #+#    #+#             */
/*   Updated: 2020/05/01 17:56:22 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**	Return room name separated from room coordinates
*/

char	*ft_get_room_name(char *line)
{
	int		end;
	char	*name;

	end = ft_strlen(line) - 1;
	while (end >= 0 && line[end] == ' ')
		end--;
	while ((end >= 0 && line[end] >= '0' && line[end] <= '9'))
		end--;
	if (line[end] == '-' || line[end] == '+')
		end--;
	while (end >= 0 && line[end] == ' ')
		end--;
	while ((end >= 0 && line[end] >= '0' && line[end] <= '9'))
		end--;
	if (line[end] == '-' || line[end] == '+')
		end--;
	if (ft_memchr(line, '-', end))
		ft_exit("Error: ivalid symbol \"-\" in room name", "");
	name = ft_strsub(line, 0, end);
	if (name == NULL)
		ft_exit(NULL, NULL);
	return (name);
}

/*
**	Try to save room if it is unic and don't have "-" sign
**	in name
*/

int		ft_add_room(t_anthill *anthill, char *line, int x, int y)
{
	t_room room;

	room.x = x;
	room.y = y;
	room.visited = -1;
	room.connected_rooms = NULL;
	room.name = ft_get_room_name(line);
	if (ft_get_room_adress(room.name, anthill))
		ft_exit("Error: Duble room name", room.name);
	if (ft_lstp2back(&anthill->rooms, &room, sizeof(room)))
		ft_exit(NULL, NULL);
	if (ft_lstp2back(&anthill->map, line, ft_strlen(line) + 1))
		ft_exit(NULL, NULL);
	return (EXIT_SUCCESS);
}

/*
**	Check line for posible canidate (3 word, last 2 - integer)
**	Try to save room;
*/

int		ft_is_room(char *line, t_anthill *anthill)
{
	char	**tmp_array;
	int		len;
	int		x;
	int		y;

	if (!(tmp_array = ft_strsplit(line, ' ')))
		ft_exit(NULL, NULL);
	if ((line[0] == 'L') || (len = ft_array_len(tmp_array)) < 3 ||\
	(ft_str_is_int(tmp_array[len - 2], &x) ||\
	ft_str_is_int(tmp_array[len - 1], &y)))
	{
		ft_clean_array(&tmp_array);
		return (EXIT_FAILURE);
	}
	ft_add_room(anthill, line, x, y);
	ft_clean_array(&tmp_array);
	return (EXIT_SUCCESS);
}

/*
**	Try read and save start or end room
*/

int		ft_get_start_end(char *line, t_anthill *anthill)
{
	if (ft_strequ(line, "##start"))
	{
		if (anthill->start_room)
			ft_exit("Error: second start room detected", "");
		if (get_next_line(0, &line) <= 0)
			ft_exit(NULL, NULL);
		if (ft_is_room(line, anthill))
			ft_exit("Error: expected room instead:", line);
		anthill->start_room = ft_get_room_name(line);
	}
	else
	{
		if (anthill->end_room)
			ft_exit("Error: second end room detected", "");
		if (get_next_line(0, &line) <= 0)
			ft_exit(NULL, NULL);
		if (ft_is_room(line, anthill))
			ft_exit("Error: expected room instead:", line);
		anthill->end_room = ft_get_room_name(line);
	}
	free(line);
	return (EXIT_SUCCESS);
}

/*
**	Read comments, commands, rooms until meet unknown line
**	This line will be cheked first in ft_map_read_links
*/

int		ft_map_read_rooms(char **line, t_anthill *anthill)
{
	int read_state;
	int error;

	while ((read_state = get_next_line(0, line)) > 0)
	{
		if (ft_is_comment(*line, &anthill->map) == 0 ||
			(error = ft_is_command(*line, &anthill->map)) == 0 ||
			(error == 1 &&
			ft_get_start_end(*line, anthill) == 0) ||
			ft_is_room(*line, anthill) == 0)
		{
			free(*line);
			continue;
		}
		break ;
	}
	if (read_state == -1)
		ft_exit(NULL, NULL);
	if (anthill->rooms == NULL)
		ft_exit("Error: No rooms found", "");
	if (anthill->start_room == NULL)
		ft_exit("Error: No start room found", "");
	if (anthill->end_room == NULL)
		ft_exit("Error: No end room found", "");
	return (EXIT_SUCCESS);
}
