/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:03:56 by majosue           #+#    #+#             */
/*   Updated: 2019/11/12 20:56:59 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	if (lst->next != NULL)
	{
		if (!(tmp = f(lst)))
			return (NULL);
		if (!(tmp->next = ft_lstmap(lst->next, f)))
		{
			free(tmp->content);
			tmp->content = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
	else
	{
		if (!(tmp = f(lst)))
			return (NULL);
	}
	return (tmp);
}
