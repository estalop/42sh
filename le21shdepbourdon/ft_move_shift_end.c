/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_shift_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:15:34 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:41:11 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_move_shift_end(t_dlist *list)
{
	int		pos;

	pos = list->pos + 1;
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\t") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\n") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\v") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\r") != 0 &&
			pos < list->length)
	{
		ft_right(list);
		pos = list->pos;
	}
	if (ft_strcmp(ft_get_element_from_list(list, pos + 1), " ") == 0)
	{
		while ((ft_strcmp(ft_get_element_from_list(list, pos), " ") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\t") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\n") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\v") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\r") == 0) &&
				pos < list->length)
		{
			ft_right(list);
			pos = list->pos;
		}
		ft_left(list);
		pos = list->pos;
	}
	return (0);
}
