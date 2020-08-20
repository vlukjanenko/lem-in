# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 12:44:31 by yquaro            #+#    #+#              #
#    Updated: 2019/08/02 16:27:31 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_buffinit.c ft_buffdel.c ft_buffadd.c ft_buffaddsymb.c
OBJECTS = ft_buffinit.o ft_buffdel.o ft_buffadd.o ft_buffaddsymb.o

NAME = libbuff.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_buffer

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
	