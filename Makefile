# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/08/27 16:13:24 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
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
	
$(LIBFT): libft/*.c libft/*.h	
	@make -C libft/

$(LIBFTPRINTF):
	@make -C libftprintf/

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
	@make -C libft/ clean
	@make -C libftprintf/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C libftprintf/ fclean

re: fclean all
