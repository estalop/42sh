#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 14:13:18 by jbobin            #+#    #+#              #
#    Updated: 2016/09/26 09:53:11 by jbobin           ###   ########.fr        #
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