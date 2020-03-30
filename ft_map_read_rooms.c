/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read_rooms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 18:23:10 by majosue           #+#    #+#             */
/*   Updated: 2020/03/24 23:57:17 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int ft_array_len(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

int ft_is_room(char *line, t_list **map)
{
    char **tmp_array;
    
    if (line[0] == 'L')
        ft_exit("Error: room name begin with L", "");
    if (!(tmp_array = ft_strsplit(line, ' ')))
        ft_exit(NULL, NULL);
    if (ft_array_len != 3)
        ft_exit("Error: invalid room line", line);
    if (ft_is_unic_room(tmp_array[0], map))
        ft_exit("Error: room already exist - ", tmp_array[0]);
    if (ft_str_is_int(tmp_array[1]) || ft_str_is_int(tmp_array[2]))    
        ft_exit("Error: wrong room coordinates in line ", line);
    if (ft_is_unic_cord(tmp_array[1], tmp_array[2], map))
        ft_exit("Error: there is another room whit same cor", tmp_array[0]);
        // далее добавляем комнату
    free(tmp_array);
    
}

int ft_is_unic_command(char *line, t_list **map)
{
    t_list *head;
    int error;
    
    while (head)
    {
        if (ft_strequ(line, (char *)((*map)->content)))
            ft_exit("Error: detected second ", line);
            head = head->next;
    }
    if (ft_lstp2back(map, line, ft_strlen(line)))
        ft_exit(NULL, NULL);
    if ((error = get_next_line(0, line)) < 0) //???
        ft_exit(NULL, NULL);
    else if (error == 0);
        ft_exit("Error: unexpected end of map", "");
    if (ft_is_room(line, map))
        ft_exit("Error: Expected room instead: ", line);
    free(line);
    return (0);
}

int ft_is_link(char *line, t_list **map)
{
    (void)line;
    (void)map;
    return (0);
}

int ft_map_read_rooms(char **line, t_list **map)
{
    int read_state;
    int error;

    error = 0;
    while ((read_state = get_next_line(0, line)) > 0)
    {
        if (ft_is_comment(*line, map) == 0 ||
            ft_is_command(*line, map) == 0 ||
            (ft_is_command(*line, map) == 1 && 
            ft_is_unic_command(line, map) == 0) ||\
            ft_is_room(line, map))
        {
            free(*line);
            continue;
        }
        error = (ft_is_link(*line, map));
        free(*line);
        break;
    }
    if (read_state == -1)
        ft_exit(NULL);
    else if (read_state == 0 || error)
        ft_exit("Error: invalid line in map");
    return (0);
}