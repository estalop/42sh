/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 01:33:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:46:43 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_copy(t_dlist *list, t_dlist *to_paste)
{
	char	*buffer;
	char	str[2];

	if (to_paste->length > 0)
		ft_delete_list2(&to_paste);
	buffer = malloc(sizeof(char) * 7);
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		if (ft_detect_right(buffer) == 1 && list->pos < list->length)
		{
			str[0] = ft_get_element_from_list(list, list->pos + 1)[0];
			str[1] = '\0';
			to_paste = ft_add_data(to_paste, str);
			ft_right(list);
		}
		if (buffer[0] == 10)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	return (0);
}
