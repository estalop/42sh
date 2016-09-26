#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 14:13:18 by jbobin            #+#    #+#              #
#    Updated: 2016/09/26 10:06:28 by jbobin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = 21sh

SRC = main.c error.c ft_builtin.c ft_free.c ft_cd.c ft_print_env.c ft_pwd.c \
	ft_opt.c ft_split_env.c ft_environ.c ft_execute.c ft_signal.c \
	ft_init_termcap.c read_termcap.c moveset.c arrow.c shift_arrow.c \
	home_and_end.c quote.c multiline.c ft_pipe.c sub_write.c ft_redirect.c \
	ft_redirect_info.c ft_fourth_redirection.c completion/complete_me.c \
	completion/create_tree.c completion/del_memory.c completion/ft_fucknorme.c \
	completion/texec_add.c completion/texec_check.c \
	completion/texec_init.c completion/texec_new.c

SRC_O = main.o error.o ft_builtin.o ft_free.o ft_cd.o ft_print_env.o ft_pwd.o \
	ft_opt.o ft_split_env.o ft_environ.o ft_execute.o ft_signal.o \
	ft_init_termcap.o read_termcap.o moveset.o arrow.o shift_arrow.o \
	home_and_end.o quote.o multiline.o ft_pipe.o sub_write.o ft_redirect.o \
	ft_redirect_info.o ft_fourth_redirection.o complete_me.o \
	create_tree.o del_memory.o ft_fucknorme.o texec_add.o texec_check.o \
	texec_init.o texec_new.o libft/libft.a

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