# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 12:36:28 by yquaro            #+#    #+#              #
#    Updated: 2019/08/03 19:39:34 by yquaro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/libft.mk

# (ar rc)
# The c option makes you create a library if it is not available,
# and the r (replace) option replaces old object files with new versions.

# (ranlib)
# Adds a character index to the archive

SOURCES = ft_addsymb.c ft_addsymbend.c ft_atoi.c ft_bzero.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_isspace.c ft_itoa.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_numblen.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
			ft_putendl_fd.c	ft_putnbr.c ft_putnbr_fd.c \
			ft_putstr.c ft_putstr_fd.c ft_stradd.c ft_strcat.c ft_strchr.c \
			ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strencut.c \
			ft_strglue.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strnadd.c ft_strncat.c \
			ft_strncmp.c ft_strncpy.c ft_strncut.c ft_strnequ.c ft_strnew.c \
			ft_strlglue.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
			ft_strsub.c ft_strswap.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			ft_matrlen.c ft_isempty.c ft_alnumstr.c
OBJECTS = ft_addsymb.o ft_addsymbend.o ft_atoi.o ft_bzero.o \
			ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
			ft_isspace.o ft_itoa.o ft_memccpy.o \
			ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o \
			ft_numblen.o ft_putchar.o ft_putchar_fd.o ft_putendl.o \
			ft_putendl_fd.o	ft_putnbr.o ft_putnbr_fd.o \
			ft_putstr.o ft_putstr_fd.o ft_stradd.o ft_strcat.o ft_strchr.o \
			ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strencut.o \
			ft_strglue.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
			ft_strlen.o ft_strmap.o ft_strmapi.o ft_strnadd.o ft_strncat.o \
			ft_strncmp.o ft_strncpy.o ft_strncut.o ft_strnequ.o ft_strnew.o \
			ft_strlglue.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o \
			ft_strsub.o ft_strswap.o ft_strtrim.o ft_tolower.o ft_toupper.o \
			ft_matrlen.o ft_isempty.o ft_alnumstr.o

all: print $(SOURCES) $(NAME)

print:
	@echo \*\*\* Compiling libft

.c.o:
	$(COMPILING) $< -o $@

$(NAME): $(OBJECTS)
	@make -C ft_list/ all
	@make -C ft_ctime/ all
	@make -C ft_alloc/ all
	@make -C ft_math/ all
	@make -C ft_map/ all
	@make -C ft_buffer/ all
	@make -C ft_matr/ all
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@mv $(NAME) lib/$(NAME)
	@make -C lib/ all

clean:
	@make -C lib/ clean
	@make -C ft_list/ clean
	@make -C ft_ctime/ clean
	@make -C ft_alloc/ clean
	@make -C ft_math/ clean
	@make -C ft_map/ clean
	@make -C ft_buffer/ clean
	@make -C ft_matr/ clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C lib/ fclean
	@make -C ft_list/ fclean
	@make -C ft_ctime/ fclean
	@make -C ft_alloc/ fclean
	@make -C ft_math/ fclean
	@make -C ft_map/ fclean
	@make -C ft_buffer/ fclean
	@make -C ft_matr/ fclean
	@rm -f ../lib/$(NAME)

re: fclean all
