/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:03:50 by majosue           #+#    #+#             */
/*   Updated: 2020/08/10 15:38:06 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

/*
**	Exit with error message
*/

void	ft_exit(char *str, char *str2)
{
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(str2, 2);
		exit(EXIT_FAILURE);
	}
	perror(NULL);
	exit(EXIT_FAILURE);
}

/*
**	Check line in map, that must be number of ants
**	Save number ants to anthill structure;
**	0 < int > INT_MAX
*/

int		ft_is_ant_nbr(char *line, t_anthill *anthill)
{
	int number;
	void *error;

	if (!ft_str_is_int(line, &number) && number > 0)
	{
		anthill->ants = number;
		error = ft_lstp2back(&anthill->map, line, ft_strlen(line) + 1);
		if (!error)
			ft_exit(NULL, NULL);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/*
**		Check is line - command
**	save if command unknown,	return (0)
**	if known command 	save	return (1)
**	if line is not a command	return (-1)
*/

int		ft_is_command(char *line, t_list **map)
{
	void *error;

	if (line[0] && line[0] == '#' && line[1] == '#')
	{
		error = ft_lstp2back(map, line, ft_strlen(line) + 1);
		if (!error)
			ft_exit(NULL, NULL);
	}
	else
		return (-1);
	if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (1);
	return (0);
}

/*
**	Check is line - comment, save it, return 0;
**	else return 1;
*/

int		ft_is_comment(char *line, t_list **map)
{
	void *error;

	if (line[0] && line[0] == '#' && !((line[1] == '#')))
	{
		error = ft_lstp2back(map, line, ft_strlen(line) + 1);
		if (!error)
			ft_exit(NULL, NULL);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int		ft_map_read_ants(char **line, t_anthill *anthill)
{
	int read_state;
	int error;

	error = 0;
	while ((read_state = get_next_line(0, line)) > 0)
	{
		if (ft_is_comment(*line, &(anthill->map)) == 0 ||
			ft_is_command(*line, &(anthill->map)) == 0)
		{
			free(*line);
			continue;
		}
		error = (ft_is_ant_nbr(*line, anthill));
		free(*line);
		break ;
	}
	if (read_state == -1)
		ft_exit(NULL, NULL);
	else if (read_state == 0 || error)
		ft_exit("Error: no ants found", "");
	return (EXIT_SUCCESS);
}
