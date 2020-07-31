/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:35:07 by majosue           #+#    #+#             */
/*   Updated: 2020/07/19 21:16:48 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <limits.h>
# define TRUE 1
# define FALSE 0

typedef struct	s_path
{
	t_list	*path; // тут собственно будет путь (список) адресов комнат
	int		path_capacity; // тут емкость пути
	int		path_flow;	// тут сколько муравьев заружено в путь.
	int		path_len;	// тут длина пути
	int		ants_in_path; // тут наличие муравьев в пути
}				t_path;

typedef struct	s_path_set
{
	t_list	*paths; // тут набор путей для сета (t_path*)paths->content-> 
	int		number_lines;
	int		paths_number;	// тут количество путей в сете !!! не нужно. Выкинуть.
}				t_path_set;

/*
**	Structure for anthill
**	in rooms we store rooms
**	(t_room*)(rooms->content)
**	in map we store input map
*/

typedef struct  s_anthill
{
	int		ants;
	t_list	*start_room;
	t_list	*end_room;
	t_list	*map;
	t_list	*rooms;
	t_list	*path_set;
	int		number_lines; // тут хранится номер оптимального набора путей
	int		last_used_path; // тут последний используемый путь из набора
}               t_anthill;

/*
**	Structure for rooms
**	in connected_rooms
**	we store (t_link*)(connected_rooms->content)
*/

typedef struct  s_room
{
	char    *name;
	int     x;
	int     y;
	int		visited;
	int		used; // временно вспомогательная для проверки уникальности в путях
	int		exist;
	char	*ant;
	t_list *from_room;
	t_list *connected_rooms;
}               t_room;

/*
**	Structure for links
**	in room we store anthill->rooms
**	store (t_list*)room from anthill
*/

typedef struct	s_link
{
	t_list	*room; 
	int		flow;
	int		capacity;
	int		disable;
}				t_link;

t_list	*ft_lstp2back(t_list **begin_list, void const *content, size_t content_size);
int     ft_map_read_ants(char **line, t_anthill *anthill);
void	ft_exit(char *str, char *str2);
int		ft_is_command(char *line, t_list **map);
int		ft_is_comment(char *line, t_list **map);
int		ft_map_read_rooms(char **line, t_anthill *anthill);
long	ft_atoi_base(const char *nbr, unsigned int base);
int		ft_str_is_int(char *line, int *number);
t_list	*ft_get_room_adress(char *name, t_anthill *anthill);
void	ft_clean_array(char ***array);
int		ft_array_len(char **array);
int		ft_map_read_links(char **line,  t_anthill *anthill);
void	del(void *content, size_t size);
t_list	*ft_dequeue(t_list **queue);
int 	ft_get_flow_from_connected(t_list *connected_rooms);
t_room	*ft_get_room_from_connected(t_list *connected_rooms);
int		ft_karp(t_anthill *anthill);
t_list	*ft_get_room_adress_from_connected(t_list *connected_rooms);
t_link	*ft_get_link_from_connected(t_list *connected_rooms);
t_room	*ft_get_room_from_anthill(t_list *rooms);
void	ft_set_edge(t_list *in_room, t_list *out_room, int flow, int capacity);
void	ft_print_graf(t_anthill *anthill);
t_link	*ft_find_link(t_list *node, t_list *connected_room);
int		ft_find_nbr_lines(t_anthill *anthill, int last_used_path, int last_used_path_len);
void	del_path(void *content, size_t size);
void	del_pathset(void *content, size_t size);



#endif