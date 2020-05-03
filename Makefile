# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/04/29 19:31:46 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  lem-in
HEADER = lem-in.h
INCLUDES = -I libft/ 
LIBFT = libft/libft.a
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror -g
SOURCES  =  lem-in.c ft_lstp2back.c ft_map_read_ants.c ft_map_read_rooms.c \
ft_atoi_base.c ft_str_is_int.c ft_map_read_links.c

OBJECTS = $(SOURCES:.c=.o)
.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(COMPILERC) -o $(NAME) $(OBJECTS) $(INCLUDES) -L libft/ -lft
	
$(LIBFT): libft/*.c libft/*.h	
	@make -C libft/

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all