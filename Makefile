# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/03/24 21:51:45 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  lem-in
HEADER = lem-in.h
INCLUDES = -I libft/ 
LIBFT = libft/libft.a
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES  =  lem-in.c ft_lstp2back.c ft_map_read_ants.c ft_map_read_rooms.c

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
