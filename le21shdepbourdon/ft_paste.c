/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 02:34:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:43:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_paste(t_dlist *list, t_dlist *to_paste, int index, char *str)
{
	char	str2[2];

	str = ft_get_str_from_list(to_paste);
	while (str[index] != '\0')
	{
		str2[0] = str[index];
		str2[1] = '\0';
		if (list->pos + 1 > list->length)
			list = ft_add_data(list, str2);
		else
			list = ins_avant(list, str2, list->p_head ,list->pos + 1);
		index++;
	}
	index = 0;
	ft_clear_line();
	ft_move_begin();
	ft_display_list(list);
	while (index < list->length - list->pos)
	{
		tputs(tgetstr("le", NULL), 0, ft_putchar2);
		index++;
	}
	free(str);
	return (0);
}
