/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:35:07 by majosue           #+#    #+#             */
/*   Updated: 2020/03/24 22:44:12 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

int     ft_lstp2back(t_list **begin_list, void const *content, size_t content_size);
int     ft_map_read_ants(char **line, t_list **map);
void	ft_exit(char *str, char *str2);
int		ft_is_command(char *line, t_list **map);
int		ft_is_comment(char *line, t_list **map);
int		ft_map_read_rooms(char **line, t_list **map);



#endif