/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:38:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 14:53:07 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void					default_lstdel(t_list *list)
{
	list->next = NULL;
	ft_strdel(&(list->content));
	free(list);
	list = NULL;
}

void					ft_lstdel(t_list **head)
{
	t_list				*tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		if ((*head = ft_lstdelone(*head, tmp)) == NULL)
			return ;
		tmp = (*head);
	}
	default_lstdel(*head);
}
