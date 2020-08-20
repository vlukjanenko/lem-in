# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qypec <qypec@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 13:11:11 by qypec             #+#    #+#              #
#    Updated: 2019/07/31 16:12:55 by qypec            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_matrdel.c ft_matrdup.c ft_matrmemalloc.c ft_matrnew.c
OBJECTS = ft_matrdel.o ft_matrdup.o ft_matrmemalloc.o ft_matrnew.o

NAME = libmatr.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_matr

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
	