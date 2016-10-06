#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 14:13:18 by jbobin            #+#    #+#              #
#    Updated: 2016/10/03 19:23:16 by pbourdon         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 21sh

SRC = main.c error.c ft_builtin.c ft_free.c ft_cd.c ft_print_env.c ft_pwd.c \
	ft_opt.c ft_split_env.c ft_environ.c ft_execute.c ft_signal.c \
	ft_init_termcap.c read_termcap.c moveset.c arrow.c shift_arrow.c \
	home_and_end.c quote.c multiline.c ft_pipe.c sub_write.c ft_redirect.c \
	ft_redirect_info.c ft_fourth_redirection.c complete_me.c \
	create_tree.c del_memory.c ft_fucknorme.c \
	texec_add.c texec_check.c \
	texec_init.c texec_new.c \
	ft_init_histo.c\
	ft_run_history.c\
	ft_display_list.c\
	ft_display_list4.c\
	dlist_new.c\
	ft_write_history_file.c\
	ft_check_options_history.c\
	ft_get_check_file.c\
	ft_get_element_from_list.c\
	ft_ins_avant.c\
	ft_display_list3.c\
	ft_add_data.c\
	ft_del_ele_list.c\
	ft_get_history_from_file.c\
	fuck_the_norm.c\
	ft_get_home.c\
	ft_delete_list.c\
	ft_run_history2.c\
	ft_deal_exclamation.c\
	ft_replace_excla.c\


SRC_O = $(SRC:.c=.o) libft/libft.a

FLAGS = -Wall -Wextra -Werror -g

HEADERS = -I ./ -I libft/includes/ -I completion

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) $(HEADERS)
	@make -C libft
	@gcc $(FLAGS) -ltermcap -o $(NAME) $(SRC_O) $(HEADERS)
	@echo make
clean:
	@rm -f $(SRC_O)
	@make clean -C libft
	@echo clean

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo fclean

re: fclean all