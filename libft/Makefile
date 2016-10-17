# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:52:20 by jbobin            #+#    #+#              #
#    Updated: 2016/10/17 16:25:06 by tviviand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr.c\
	ft_strcmp.c ft_striter.c ft_strmap.c ft_strnequ.c ft_strstr.c ft_isalpha.c \
	ft_memalloc.c ft_memdel.c ft_putendl.c ft_putstr_fd.c ft_strcpy.c \
	ft_striteri.c ft_strmapi.c ft_strnew.c ft_strsub.c ft_isascii.c \
	ft_memccpy.c ft_memmove.c ft_putendl_fd.c ft_strcat.c ft_strdel.c \
	ft_strjoin.c ft_strncat.c ft_strnstr.c ft_strtrim.c ft_atoi.c ft_isdigit.c \
	ft_memchr.c	ft_memset.c ft_putnbr.c ft_strchr.c ft_strdup.c ft_strlcat.c \
	ft_strncmp.c ft_strrchr.c ft_tolower.c ft_bzero.c ft_isprint.c ft_memcmp.c \
	ft_putchar.c ft_putnbr_fd.c ft_strclr.c ft_strequ.c ft_strlen.c \
	ft_strncpy.c ft_strsplit.c ft_toupper.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c	ft_lstiter.c ft_lstmap.c ft_printbits.c \
	ft_lstnewnext.c get_next_line.c	ft_strcnt.c ft_split.c ft_tabdup.c \
	ft_tabdup_plusone.c ft_tablen.c	ft_print_tab.c ft_free_tab.c \
	ft_deltab.c ft_strndup.c ft_putxchar.c ft_wctomb.c ft_wcstombs.c \
	ft_wcslen.c ft_llitoa.c ft_binsize.c ft_ullitoa_base.c ft_ullitoa.c\
	ft_llitob.c ft_putstr_unless.c ft_putstr_until.c ft_wcscbytes.c \
	ft_strjoind.c

SRCPRINTF = printf/args_par.c printf/cast.c printf/colors.c \
			printf/ft_printf.c printf/notype.c printf/print_types.c \
			printf/types.c

SRC_o = $(SRC:.c=.o)

PRINTF_o = args_par.o cast.o colors.o \
			ft_printf.o notype.o print_types.o \
			types.o

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -g -I includes/ -c $(SRC) $(SRCPRINTF)
	@ar rc $(NAME) $(SRC_o) $(PRINTF_o)
	@ranlib $(NAME)

clean:
	@rm -f $(SRC_o) $(PRINTF_o)

fclean: clean
	@rm -f $(NAME)

re: fclean all
