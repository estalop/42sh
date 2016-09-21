/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_and_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 14:03:10 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 15:58:38 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_move_and_clean(t_dlist *list)
{
	char			*str;
	int				index;
	int				index2;
	struct winsize	sz;

	index2 = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	str = ft_get_str_from_list(list);
	index = ft_strlen(str);
	index = index / sz.ws_col;
	while (list->pos > 0)
		ft_left(list);
	ft_clear_line();
	ft_move_begin();
	while (index2 < index)
	{
		ft_down(list);
		ft_move_begin();
		ft_clear_line();
		index2++;
	}
	index2 = 0;
	while (index2 < index)
	{
		ft_up(list);
		ft_clear_line();
		index2++;
	}
	ft_move_begin();
	free(str);
}
