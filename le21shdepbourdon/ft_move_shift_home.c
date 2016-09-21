/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_shift_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:37:51 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:41:30 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_move_shift_home(t_dlist *list)
{
	int		pos;

	pos = list->pos - 1;
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") == 0 && pos > 0)
	{
		ft_left(list);
		pos = list->pos;
	}
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") != 0 && pos > 0)
	{
		ft_left(list);
		pos = list->pos;
	}

	return (0);
}
