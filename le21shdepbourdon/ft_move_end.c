/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:17:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:44:43 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_move_end(t_dlist *list)
{
	int		pos;
	struct winsize sz;
	int		index;

	ioctl(0, TIOCGWINSZ, &sz);


	pos = list->length - list->pos;
	while (pos > 0)
	{
		ft_right(list);
		pos--;
	}
	return (0);
}
