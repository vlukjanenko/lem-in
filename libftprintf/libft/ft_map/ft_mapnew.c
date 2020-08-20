/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:04:28 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 14:56:22 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_map					*ft_mapnew(void *hashfunc_ptr, int size)
{
	t_map				*map;
	int					i;

	i = 0;
	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if (hashfunc_ptr != NULL)
		map->hashfunc = hashfunc_ptr;
	else
		map->hashfunc = DEFAULT_HASHFUNC;
	if (size == 0)
		map->size = DEFAULT_MAP_SIZE;
	else
		map->size = size;
	map->head = (t_hlist **)malloc(sizeof(t_hlist *) * map->size);
	while (i < map->size)
		map->head[i++] = NULL;
	return (map);
}
