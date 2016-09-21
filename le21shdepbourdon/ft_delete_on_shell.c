/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_on_shell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 16:39:52 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 12:41:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_delete_on_shell(t_dlist *list)
{

	if (list->pos != 0)
	{
		tputs(tgetstr("le", NULL), 0, ft_putchar2);
		list = ft_del_ele_list(list, list->pos, list->p_head, 1);
		ft_clear_n_char(1);
	}
	return (0);
}
