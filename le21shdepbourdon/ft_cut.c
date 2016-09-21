/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 01:33:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:37:10 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		ft_cut2(t_dlist *list, char *str, t_dlist *to_paste)
{
	str[0] = ft_get_element_from_list(list, list->pos + 1)[0];
	str[1] = '\0';
	to_paste = ft_add_data(to_paste, str);
	ft_right(list);
}

int			ft_cut3(t_dlist *list, int *tab2, int index, char *buffer)
{
	index--;
	while (index >= 0)
	{
		ft_del_ele_list(list, tab2[index], list->p_head, 1);
		index--;
	}
	ft_move_begin();
	ft_clear_line();
	ft_display_list(list);
	free(buffer);
	free(tab2);
	return (0);
}

int			ft_cut(t_dlist *list, t_dlist *to_paste, int index, char *buffer)
{
	char	str[2];
	int		*tab2;

	tab2 = malloc(sizeof(int) * ft_list_size(list->p_head));
	if (to_paste->length > 0)
		ft_delete_list2(&to_paste);
	buffer = malloc(sizeof(char) * 7);
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		if (ft_detect_right(buffer) == 1 && list->pos < list->length)
		{
			tab2[index] = list->pos + 1;
			index++;
			ft_cut2(list, str, to_paste);
		}
		if (buffer[0] == 10)
			return (ft_cut3(list, tab2, index, buffer));
	}
	free(tab2);
	free(buffer);
	return (0);
}
