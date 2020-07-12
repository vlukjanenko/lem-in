/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:35:07 by majosue           #+#    #+#             */
/*   Updated: 2020/05/03 18:35:08 by majosue          ###   ########.fr       */
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

/*
**	Structure for anthill
**	in rooms we store rooms
**	(t_room*)(rooms->content)
**	in map we store input map
*/

typedef struct  s_anthill
{
	int		ants;
	char	*start_room;
	char	*end_room;
	t_list	*map;
	t_list	*rooms;
}               t_anthill;

/*
**	Structure for rooms 
**	(in connected_rooms we store adresses rooms from s_anthill)
**	*(t_list**)(connected_rooms->content) = (t_list*)room from anthill
*/

typedef struct  s_room
{
	char    *name;
	int     x;
	int     y;
	int		visited;
	t_list *connected_rooms;
}               t_room;


int     ft_lstp2back(t_list **begin_list, void const *content, size_t content_size);
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
int		ft_find_path(t_anthill *anthill);

#endif