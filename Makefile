# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/08/14 06:58:49 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
NAME2 = visuhex
HEADER = lem_in.h
INCLUDES = -I libft/ -I libftprintf/
LIBFT = libft/libft.a
LIBFTPRINTF = libftprintf/libftprintf.a
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror -g
SOURCES  =  lem_in.c ft_lstp2back.c ft_map_read_ants.c ft_map_read_rooms.c \
ft_atoi_base.c ft_str_is_int.c ft_map_read_links.c ft_find_path.c \
ft_free_anthill.c ft_run_ants.c ft_find_nbr_lines.c ft_add_path_to_set.c \
ft_getters.c ft_mark_path.c ft_find_augmenting_path.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: clean fclean re

all: $(NAME) $(NAME2)

$(NAME): $(OBJECTS) $(LIBFT) $(LIBFTPRINTF)
	$(COMPILERC) -o $(NAME) $(OBJECTS) $(INCLUDES) -L libft/ -lft -L libftprintf/ -lftprintf
	
$(NAME2): ./visu-hex/bin/VisuHex.class ./visu-hex/src/VisuHex.java
	echo '#!/bin/sh' > $(NAME2)
	echo "java -cp ./visu-hex/lib/gs-core-1.3.jar:./visu-hex/bin VisuHex" >> $(NAME2)
	chmod +x $(NAME2)

./visu-hex/bin/VisuHex.class: ./visu-hex/src/VisuHex.java ./visu-hex/bin
	javac -cp ./visu-hex/lib/gs-core-1.3.jar ./visu-hex/src/VisuHex.java -d ./visu-hex/bin

./visu-hex/bin:
	mkdir ./visu-hex/bin
	
$(LIBFT): libft/*.c libft/*.h	
	@make -C libft/

$(LIBFTPRINTF): $(LIBFT) libftprintf/*.c libftprintf/*.h
	@make -C libftprintf/

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
	@rm -f $(NAME2)
	@rm -rf ./visu-hex/bin
	@make -C libft/ clean
	@make -C libftprintf/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C libftprintf/ fclean

re: fclean all
