# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 13:54:33 by yquaro            #+#    #+#              #
#    Updated: 2019/08/02 14:58:32 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_hashfunc.c ft_mapinsert.c ft_mapnew.c ht_list.c \
			ft_mapdelone.c ft_ismapitem.c ft_getvalue.c ft_mapdel.c
OBJECTS = ft_hashfunc.o ft_mapinsert.o ft_mapnew.o ht_list.o \
			ft_mapdelone.o ft_ismapitem.o ft_getvalue.o ft_mapdel.o

NAME = libhashtab.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_hashtab

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) ../lib/$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f ../lib/$(NAME)