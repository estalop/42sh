# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 14:13:18 by jbobin            #+#    #+#              #
#    Updated: 2016/11/01 14:59:23 by jbobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

SRC_DIR = src

OBJ_DIR = obj

INC_DIR = inc

SRC = main.c error.c ft_builtin.c ft_free.c ft_cd.c ft_print_env.c ft_pwd.c \
	ft_opt.c ft_split_env.c ft_environ.c ft_execute.c ft_signal.c \
	ft_init_termcap.c read_termcap.c moveset.c arrow.c shift_arrow.c \
	home_and_end.c quote.c multiline.c ft_pipe.c sub_write.c ft_redirect.c \
	ft_redirect_info.c ft_fourth_redirection.c complete_me.c \
	create_tree.c del_memory.c ft_fucknorme.c \
	texec_add.c texec_check.c \
	texec_init.c texec_new.c tfiles_getlst.c tfiles_getlst2.c \
	ft_select.c ft_select_moves.c ft_select_printlist.c \
	ft_init_histo.c \
	ft_run_history.c \
	ft_display_list.c \
	dlist_new.c \
	ft_write_history_file.c \
	ft_check_options_history.c \
	ft_get_check_file.c \
	ft_get_element_from_list.c \
	ft_ins_avant.c \
	ft_add_data.c \
	ft_del_ele_list.c \
	ft_get_history_from_file.c \
	fuck_the_norm.c \
	ft_get_home.c \
	ft_delete_list.c \
	ft_run_history2.c \
	ft_deal_exclamation.c \
	ft_replace_excla.c \
	ft_check_tmp.c \
	ft_print_cd.c \
	ft_curpath_cd.c \
	ft_echo.c \
	ft_autocompletion.c

SRC_O = $(SRC:.c=.o)

DSRC = $(addprefix $(SRC_DIR)/,$(SRC))

DOBJ = $(addprefix $(OBJ_DIR)/,$(SRC_O))

FLAGS = -Wall -Wextra -Werror -g

HEADERS = -I ./$(INC_DIR) -I libft/includes/ -I completion

all: $(NAME)

$(NAME):
	make -C libft/
	mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -I./libft -I./$(INC_DIR) -c $(DSRC)
	mv $(SRC_O) $(OBJ_DIR)
	gcc $(FLAGS) libft/libft.a -I./$(INC_DIR) -L./libft -lft -ltermcap -o $(NAME) $(DOBJ)

clean:
	make -C libft/ clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
