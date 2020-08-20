/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:22:52 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 14:52:46 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "../includes/libft.h"

typedef struct					s_list
{
	char						*content;
	struct s_list				*next;
}								t_list;

void							ft_lstdel(t_list **head);
void							default_lstdel(t_list *list);
t_list							*ft_lstdelone(t_list *head, t_list *dellist);
void							ft_lstadd(t_list **alst, t_list *new);
void							ft_lstpushback(t_list **head, t_list *new);
t_list							*ft_lstnew(const char *content);
int								ft_listsize(t_list *head);

#endif
