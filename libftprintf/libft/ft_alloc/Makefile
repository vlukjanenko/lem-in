# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 12:36:22 by yquaro            #+#    #+#              #
#    Updated: 2019/08/02 16:26:43 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_realloc.c ft_memalloc.c ft_memdel.c ft_strdel.c
OBJECTS = ft_realloc.o ft_memalloc.o ft_memdel.o ft_strdel.o

NAME = liballoc.a


all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_alloc

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
