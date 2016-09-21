# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/09/11 17:43:36 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft/
LIB = $(LIBPATH)/21sh.a

NAME = 21sh

CC = @gcc -lncurses

CFLAGS =

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		ft_tc.c\
		ft_get_user_input.c\
		ft_detect_arrows.c\
		ft_move_cursor_simple.c\
		ft_clear_n_char.c\
		ft_deal_input.c\
		ft_detect_ctrl.c\
		ft_delete_on_shell.c\
		ft_add_element.c\
		ft_finish_command.c\
		ft_detect_end.c\
		ft_move_end.c\
		ft_detect_home.c\
		ft_move_home.c\
		ft_detect_shift_home.c\
		ft_move_shift_home.c\
		ft_second_delete.c\
		ft_detect_second_delete.c\
		ft_detect_shift_end.c\
		ft_move_shift_end.c\
		ft_get_info_from_list.c\
		ft_clear_line.c\
		ft_move_begin.c\
		ft_detect_copy.c\
		ft_detect_cut.c\
		ft_detect_paste.c\
		ft_copy.c\
		ft_cut.c\
		ft_paste.c\
		ft_detect_tab.c\
		ft_detect_page_up.c\
		ft_detect_page_down.c\
		ft_move_page_up.c\
		ft_move_page_down.c\
		ft_check_correct_entry.c\
		ft_check_correct_entry2.c\
		ft_process.c\
		ft_choose.c\
		ft_show_prompt.c\
		ft_last_dir.c\
		ft_run_cd.c\
		ft_get_path.c\
		ft_home.c\
		ft_get_ele.c\
		ft_error_home.c\
		ft_exchange_element.c\
		ft_error.c\
		ft_prev.c\
		ft_run_echo.c\
		ft_run_unsetenv.c\
		ft_run_setenv.c\
		ft_check_arg.c\
		ft_get_size.c\
		ft_get_options.c\
		ft_get_total_path.c\
		ft_get_auto_path.c\
		ft_give_path.c\
		ft_run_exe.c\
		ft_check_file.c\
		ft_check_arg3.c\
		ft_get_sigint.c\
		ft_separate_dot_coma.c\
		ft_detect_dot_coma.c\
		ft_historic.c\
		ft_move_and_clean.c\
		ft_check_pipe.c\
		ft_new_arg.c\


OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	@make -C $(LIBPATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBPATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBPATH)

re: fclean all

.PHONY: all re clean flcean
