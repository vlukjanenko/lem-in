/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_nbr_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:59:44 by majosue           #+#    #+#             */
/*   Updated: 2020/08/14 06:59:52 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Распределяем начальное количество муравьёв по путям
**	в каждый путь по 1 муравью + (разницу длин последнего пути
**	и текущего) = ёмкость пути
**	возвращаем остаток нераспределенных муравьев
*/

int		ft_get_rest_ants(t_anthill *anthill, int ants, int last_path_len)
{
	int		a;
	t_list	*path;

	path = ((t_path_set *)(anthill->path_set->content))->paths;
	a = ants;
	while (path)
	{
		a = a - 1 - (last_path_len - ((t_path *)(path->content))->path_len);
		((t_path *)(path->content))->path_capacity = 1 + (last_path_len -\
		((t_path *)(path->content))->path_len);
		if (a < 0)
			a = 0;
		path = path->next;
	}
	return (a);
}

/*
**	Второе распределение. теперь емкости в путях проставлены
**	увеличиваем их на остаток муравьев равномерно.
*/

void	ft_redistribute_ants(t_anthill *anthill, int number_paths,\
int rest_ants)
{
	t_list	*paths;
	int		each_path_addon;
	int		rest;

	paths = ((t_path_set *)(anthill->path_set->content))->paths;
	each_path_addon = rest_ants / number_paths;
	rest = rest_ants % number_paths;
	while (paths)
	{
		((t_path *)(paths->content))->path_capacity +=\
		each_path_addon + ((rest > 0) ? 1 : 0);
		rest--;
		paths = paths->next;
	}
}

/*
**	Поиск количества линий для прохождения всех муравьев
*/

int		ft_find_nbr_lines(t_anthill *anthill, int paths_number,\
int last_used_path_len)
{
	int rest_ants;
	int rest_ants2;
	int nbr_lines;

	rest_ants = ft_get_rest_ants(anthill, anthill->ants, last_used_path_len);
	ft_redistribute_ants(anthill, paths_number, rest_ants);
	rest_ants2 = (rest_ants % paths_number) == 0 ? 0 : 1;
	nbr_lines = last_used_path_len + rest_ants / paths_number + rest_ants2;
	return (nbr_lines);
}
