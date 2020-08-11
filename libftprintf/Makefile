# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/08/11 14:57:22 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
HEADER = ft_printf.h
INCLUDES = ../libft/
COMPILERC = gcc
MAKERLIB = ar rc
FLAGS = -Wall -Wextra -Werror
SOURCES  =  ft_printf.c ft_lstp2back.c ft_readformat.c ft_chkflags.c \
ft_gettab.c ft_get_f.c ft_add_left.c ft_add_right.c \
ft_null.c ft_space.c ft_minus.c ft_plus.c ft_skipflags.c ft_width.c \
ft_prec.c ft_char.c ft_fmt_char.c ft_string.c ft_fmt_plus.c\
ft_itoa_base.c ft_itoa_base_u.c ft_get_size.c ft_get_size_u.c ft_sharp.c \
ft_fmt_width.c ft_fmt_prec.c ft_number.c ft_number_o.c ft_number_x.c \
ft_number_u.c ft_ftoa.c ft_float.c\
../libft/ft_atoi.c\
../libft/ft_bzero.c\
../libft/ft_isalnum.c\
../libft/ft_isdigit.c\
../libft/ft_lstdel.c\
../libft/ft_lstnew.c\
../libft/ft_memalloc.c\
../libft/ft_memchr.c\
../libft/ft_memcpy.c\
../libft/ft_memdel.c\
../libft/ft_memset.c\
../libft/ft_strcat.c\
../libft/ft_strchr.c\
../libft/ft_strjoin.c\
../libft/ft_strlen.c\
../libft/ft_strnew.c\
../libft/ft_strsub.c\
../libft/ft_isalpha.c\
../libft/ft_memmove.c\
../libft/ft_strcpy.c\
../libft/ft_strncpy.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(MAKERLIB) $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(HEADER) ../libft/libft.h
	$(COMPILERC) $(FLAGS) -I $(INCLUDES) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
#	@make -C ../libft/ clean

fclean: clean
	@rm -f $(NAME)
#	@make -C ../libft/ fclean

re: fclean all