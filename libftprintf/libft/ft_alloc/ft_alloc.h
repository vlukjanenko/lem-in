/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:52:04 by yquaro            #+#    #+#             */
/*   Updated: 2019/08/02 16:26:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_H
# define FT_ALLOC_H

# include "../includes/libft.h"

void							*ft_realloc(void *ptr, size_t newsize);
void							*ft_memalloc(size_t size);
void							ft_memdel(void **ap);
void							ft_strdel(char **as);

#endif
