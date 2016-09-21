/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_page_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:30:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 14:00:02 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_move_page_up(t_dlist *list)
{
	int		index;
	struct winsize sz;

	index = list->pos;
	ioctl(0, TIOCGWINSZ, &sz);
	index = index / sz.ws_col;
	if (index > 0)
	{
		list->pos = list->pos - sz.ws_col;
		ft_up(list);
	}
	return (0);
}
