# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:04:26 by pbourdon          #+#    #+#              #
#    Updated: 2016/09/06 12:13:26 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME	=	libft.a
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

SDIR	=	./src/
IDIR	=	./includes/
ODIR	=	./obj/

I		=	-I $(IDIR)

EXT		=	Makefile
EXT		+=	$(IDIR)libft.h

SRC		=	ft_atoi.c\
			ft_itoa.c\
			ft_memcpy.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\
			get_next_line.c\
			ft_memmove.c\
			ft_strchr.c\
			ft_strncmp.c\
			ft_delete_tab.c\
			ft_bzero.c\
			ft_strnew.c\
			ft_memalloc.c\
			ft_strcpy.c\
			ft_add_data.c\
			fuck_the_norm.c\
			ft_tab_from_list.c\
			ft_strupcase.c\
			ft_strcut.c\
			ft_strcmp2.c\
			ft_set_zero.c\
			ft_search_list.c\
			ft_list_size.c\
			ft_ins_avant.c\
			ft_free_tab.c\
			ft_display_tab.c\
			ft_display_list.c\
			ft_strcup.c\
			ft_delete_space.c\
			dlist_new.c\
			ft_cpy_env.c\
			ft_del_ele_list.c\
			ft_delete_list.c\
			ft_putchar2.c\
			ft_get_element_from_list.c\
			ft_get_str_from_list.c\
			ft_display_list2.c\
			ft_add_data3.c\
			ft_get_size_from_list.c\

OBJ		=	$(SRC:.c=.o)
	S		=	$(addprefix $(SDIR), $(SRC))
	O		=	$(addprefix $(ODIR), $(OBJ))

all: $(NAME)

test: all
	@$(CC) $(FLAGS) test/main.c -o test/test $I -L. -lft
	@./test/test

creating:
	@echo " - compiling sources\c"

$(NAME): creating $(O) $(EXT)
	@echo "\n - Creating library..."
	@ar rc $(NAME) $(O)
	@echo " - Optimizing..."
	@ranlib $(NAME)
	@echo "libft done.\n"


$(ODIR)%.o: $(SDIR)%.c $(EXT)
	@echo ".\c"
	@$(CC) $(FLAGS) -c -o $@ $< $(I)

$(O): | $(ODIR)
$(ODIR):
	@mkdir $(ODIR)

clean:
	@echo "cleaning object files..."
	@rm -rf $(ODIR)

fclean: clean
	@echo "cleaning $(NAME) binary..."
	@rm -rf $(NAME)

re: fclean all
