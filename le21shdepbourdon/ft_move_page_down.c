/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_page_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:34:16 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 15:33:58 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_move_page_down(t_dlist *list)
{
	int		index;
	struct winsize sz;
	int		index2;

	ioctl(0, TIOCGWINSZ, &sz);
	index = list->pos % sz.ws_col;
	index2 = index;
	if (index + (list->length - list->pos) >= sz.ws_col)
	{
		ft_down(list);
		list->pos = list->pos + (sz.ws_col - index) + 1;
		while (index > 1)
		{
			ft_right(list);
			index--;
		}
	}
	return (0);
}
