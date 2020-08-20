# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:07:18 by yquaro            #+#    #+#              #
#    Updated: 2019/08/02 16:08:03 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/printf.mk

SOURCES = ft_printf.c color.c print_arg.c init_part.c \
	print_date.c parse.c struct_spec.c is_it_something.c init_width.c \
	print_diu.c ft_itoa_base.c print_char.c print_dl_dll.c print_int.c \
	print_float.c display_int.c gspec.c rounding.c ft_fill_part.c \
	print_matrix.c

OBJECTS = ft_printf.o color.o print_arg.o init_part.o \
	print_date.o parse.o struct_spec.o is_it_something.o init_width.o \
	print_diu.o ft_itoa_base.o print_char.o print_dl_dll.o print_int.o \
	print_float.o display_int.o gspec.o rounding.o ft_fill_part.o \
	print_matrix.o

NAME = printf.a

all: print $(SOURCES) $(NAME)

print:
	@echo \*\*\* Compiling ft_printf

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



