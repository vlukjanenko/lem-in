/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:58:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 14:58:06 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include "../includes/libft.h"
# include <stdarg.h>

# define DEFAULT_MAP_SIZE 100
# define DEFAULT_HASHFUNC &ft_hashfunc

typedef struct			s_htablist
{
	char				*key;
	void				*value;
	struct s_htablist	*next;
}						t_hlist;

typedef struct			s_map
{
	t_hlist				**head;
	int					size;
	void				*hashfunc;
}						t_map;

t_hlist					*ht_listnew(const char *key, const void *value);
t_hlist					*ht_listdelone(t_hlist *head, t_hlist *dellist);
void					ht_listdel(t_hlist **head);

int						ft_hashfunc(const char *str, int size);

t_map					*ft_mapnew(void *hashfunc_ptr, int size);
int						ft_ismapitem(t_map *map, const char *key);
const char				*ft_mapvalue(const t_map *map, const char *key);
void					ft_mapinsert(t_map *map, const char *key, \
										const void *value);
void					ft_mapdelone(t_map *map, const char *key);
void					ft_mapdel(t_map **map);
void					ft_putmap(t_map *map);

#endif
