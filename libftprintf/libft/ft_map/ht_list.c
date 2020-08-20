/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:30:10 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 15:02:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

static void				default_del(t_hlist *list)
{
	list->next = NULL;
	list->key = NULL;
	list->value = NULL;
	free(list);
	list = NULL;
}

t_hlist					*ht_listdelone(t_hlist *head, t_hlist *dellist)
{
	t_hlist				*tmp;
	t_hlist				*lst;

	if (dellist == NULL)
		return (NULL);
	tmp = head;
	lst = dellist;
	if (tmp == lst)
	{
		head = head->next;
		default_del(lst);
		lst = head;
		return (lst);
	}
	if (tmp->next != NULL)
	{
		while (tmp->next != lst)
			tmp = tmp->next;
		tmp->next = lst->next;
	}
	default_del(lst);
	return (head);
}

void					ht_listdel(t_hlist **head)
{
	t_hlist				*tmp;

	if (*head == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		if ((*head = ht_listdelone(*head, tmp)) == NULL)
			return ;
		tmp = (*head);
	}
	default_del(*head);
}

t_hlist					*ht_listnew(const char *key, const void *value)
{
	t_hlist				*list;

	if ((list = (t_hlist *)malloc(sizeof(t_hlist))) == NULL)
		return (NULL);
	list->key = (char *)key;
	list->value = (void *)value;
	list->next = NULL;
	return (list);
}
