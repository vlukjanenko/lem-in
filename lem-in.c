/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:33:02 by majosue           #+#    #+#             */
/*   Updated: 2020/03/24 22:03:54 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int ft_map_read(t_list **map)
{
	char *line;
	line = NULL;
	*map = NULL;
	ft_map_read_ants(&line, map);
	ft_map_read_rooms(&line, map);
    /*ft_map_read_links(&line, &map); */
	return (0);
}

int main(int argc, char **argv)
{
	t_list *map;

	ft_map_read(&map);
	(void)argc;
	(void)argv;
}
