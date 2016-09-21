/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:27:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 15:52:59 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_deal_input(char *buffer, t_dlist *list, t_dlist *histo,
			t_dlist *to_paste)
{
	/*
	ft_putchar('\n');
	ft_putnbr(buffer[0]);
	ft_putchar(' ');
	ft_putnbr(buffer[1]);
	ft_putchar(' ');
	ft_putnbr(buffer[2]);
	ft_putchar(' ');
	ft_putnbr(buffer[3]);
		ft_putchar(' ');
	ft_putnbr(buffer[4]);
	ft_putchar(' ');
	ft_putnbr(buffer[5]);
	ft_putchar(' ');
*/
	if (ft_detect_second_delete(buffer) == 1)
		return (ft_second_delete(list));
	if (ft_detect_ctrl_d(buffer) == 1)
		exit(EXIT_SUCCESS);
	else if (ft_detect_right(buffer) == 1)
		return (ft_right(list));
	else if (ft_detect_left(buffer) == 1)
		return (ft_left(list));
	else if (ft_detect_up(buffer) == 1)
		return (ft_historic_previous(list, histo));
	else if (ft_detect_down(buffer) == 1)
		return (ft_historic_after(list, histo));
	else if (ft_detect_copy(buffer) == 1)
		return (ft_copy(list, to_paste));
	else if (ft_detect_cut(buffer) == 1)
		return (ft_cut(list, to_paste, 0, NULL));
	else if (ft_detect_paste(buffer) == 1)
		return (ft_paste(list, to_paste, 0, "alpha"));
	else
		return (ft_deal_input2(buffer, list, histo, to_paste));
}

int		ft_deal_input2(char *buffer, t_dlist *list, t_dlist *histo,
			t_dlist *to_paste)
{
	if (buffer[0] == 127) // delete button
		return (ft_delete_on_shell(list));
	else if (buffer[0] == 10) // enter button
		return (ft_finish_command(list, histo));
	else if (ft_detect_end(buffer) == 1)
		return (ft_move_end(list));
	else if (ft_detect_home(buffer) == 1)
		return (ft_move_home(list));
	else if (ft_detect_shift_home(buffer) == 1)
		return (ft_move_shift_home(list));
	else if (ft_detect_shift_end(buffer) == 1)
		return (ft_move_shift_end(list));
	else if (ft_detect_tab(buffer) == 1)
		return (0);
	else if (ft_detect_page_up(buffer) == 1)
		return (ft_move_page_up(list));
	else if (ft_detect_page_down(buffer) == 1)
		return (ft_move_page_down(list));
	else
		return (ft_add_element(list, buffer));
	return (0);
}
