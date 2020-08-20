/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrmemalloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:50:35 by qypec             #+#    #+#             */
/*   Updated: 2019/07/31 16:17:38 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matr.h"

char				**ft_matrmemalloc(size_t size)
{
	char			**matr;
	int				i;

	if ((matr = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= (int)size)
		matr[i++] = NULL;
	return (matr);
}
