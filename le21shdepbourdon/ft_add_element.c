/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 17:42:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:44:07 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_add_element(t_dlist *list, char *buffer)
{
	char	test[2];

	test[0] = buffer[0];
	test[1] = '\0';
	if (list->pos == list->length)
	{
		ft_putchar(test[0]);
		list = ft_add_data(list, test);
	}
	else
	{
		tputs(tgetstr("im", NULL), 0, ft_putchar2);
		ft_putchar(test[0]);
		tputs(tgetstr("ei", NULL), 0, ft_putchar2);
		list = ins_avant(list, test, list->p_head, list->pos + 1);
	}
	return (0);
}
