/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 07:44:18 by majosue           #+#    #+#             */
/*   Updated: 2019/09/28 17:36:05 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int		shift(char **line, t_bufer **bufer)
{
	char	*bufer2;

	bufer2 = ft_strsub((*bufer)->bufer, ft_strlen(*line) + 1,\
ft_strlen((*bufer)->bufer) - 1 - ft_strlen(*line));
	if (!bufer2)
		return (-1);
	free((*bufer)->bufer);
	(*bufer)->bufer = bufer2;
	return (1);
}

int		afterfill(int fd, t_bufer **bufer)
{
	ssize_t	i;
	char	*bufer2;
	char	*rest;

	i = 1;
	while ((ft_strchr((*bufer)->bufer, '\n')) == 0 && i > 0)
	{
		if (!(rest = ft_strdup((*bufer)->bufer)))
			return (-1);
		free((*bufer)->bufer);
		if (!((*bufer)->bufer = ft_strnew(BUFF_SIZE)))
			return (-1);
		i = read(fd, (*bufer)->bufer, BUFF_SIZE);
		if (!(bufer2 = ft_strjoin(rest, (*bufer)->bufer)))
			return (-1);
		free((*bufer)->bufer);
		free(rest);
		(*bufer)->bufer = bufer2;
	}
	return (i);
}

int		getbufer(int fd, t_bufer **bufer)
{
	while ((*bufer)->fd != fd && (*bufer)->next)
		*bufer = (*bufer)->next;
	if ((*bufer)->fd != fd && (*bufer)->next == NULL)
	{
		if (!((*bufer)->next = malloc(sizeof(t_bufer))))
			return (-1);
		(*bufer)->next->prev = *bufer;
		(*bufer) = (*bufer)->next;
		(*bufer)->fd = fd;
		(*bufer)->bufer = NULL;
		(*bufer)->next = NULL;
	}
	return (1);
}

int		fillb(int fd, t_bufer **bufer)
{
	ssize_t i;

	if (!*bufer)
	{
		if (!(*bufer = malloc(sizeof(t_bufer))))
			return (-1);
		(*bufer)->fd = fd;
		(*bufer)->bufer = NULL;
		(*bufer)->next = NULL;
		(*bufer)->prev = NULL;
	}
	if ((getbufer(fd, bufer)) == -1)
		return (-1);
	if (!(*bufer)->bufer)
	{
		if (!((*bufer)->bufer = ft_strnew(BUFF_SIZE)))
			return (-1);
		i = read(fd, (*bufer)->bufer, BUFF_SIZE);
		if (i == -1 || i == 0)
			return (i);
	}
	i = afterfill(fd, bufer);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_bufer	*bufer;
	char			*end;
	ssize_t			i;

	if (bufer)
		while (bufer->prev)
			bufer = bufer->prev;
	if ((i = fillb(fd, &(bufer))) == -1)
		return (-1);
	if ((end = ft_strchr(bufer->bufer, '\n')))
	{
		if (!(*line = ft_strsub(bufer->bufer, 0, end - (bufer->bufer))))
			return (-1);
		i = shift(line, &bufer);
		return (i);
	}
	if (*(bufer->bufer))
	{
		if (!(*line = ft_strdup(bufer->bufer)))
			return (-1);
		*(bufer->bufer) = 0;
		return (1);
	}
	return (i);
}
