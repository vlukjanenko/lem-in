/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qypec <qypec@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:32:02 by qypec             #+#    #+#             */
/*   Updated: 2019/08/03 18:23:39 by qypec            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATR_H
# define FT_MATR_H

#include "../includes/libft.h"

char					**ft_matrnew(size_t matr_size, ...);
char					**ft_matrmemalloc(size_t size);
char					**ft_matrdup(const char *first_str, ...);
void					*ft_matrdel(char ***ret);

#endif