# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 17:26:14 by yquaro            #+#    #+#              #
#    Updated: 2019/07/25 17:30:14 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../includes/libft.mk

SOURCES = ft_uctime.c ft_ctime.c getdata.c getmonth.c get_temporarydata.c \
			struct_to_str.c
OBJECTS = ft_uctime.o ft_ctime.o getdata.o getmonth.o get_temporarydata.o \
			struct_to_str.o

NAME = libctime.a

all: print $(SOURCES) $(NAME)
	
print:
	@echo \*\*\* Compiling ft_ctime

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
