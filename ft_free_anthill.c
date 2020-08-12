/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_anthill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:38:48 by majosue           #+#    #+#             */
/*   Updated: 2020/08/12 22:00:10 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
**	Clean up memory
*/

void	del(void *content, size_t size)
{
	if (content)
	{
		ft_bzero(content, size);
		ft_memdel(&content);
	}
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

void	ft_free_anthill(t_anthill *anthill)
{
	if (anthill->map)
		ft_lstdel(&(anthill->map), del);
	if (anthill->rooms)
		ft_lstdel(&(anthill->rooms), del_room);
	if (anthill->path_set)
		ft_lstdel(&(anthill->path_set), del_pathset);
}
