/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:11:07 by qypec             #+#    #+#             */
/*   Updated: 2019/07/31 16:16:11 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matr.h"

void				*ft_matrdel(char ***ret)
{
	char	**tmp;
	int		i;

	if (*ret == NULL)
		return (NULL);
	tmp = *ret;
	i = 0;
	while (tmp[i] != NULL)
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
	*ret = tmp;
	return (NULL);
}
