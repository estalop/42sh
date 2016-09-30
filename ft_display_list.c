/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:13:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/30 14:42:40 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_display_list(t_dlist *p_list, int i)
{
	t_node		*p_temp;

	p_temp = p_list->p_head;
	if (p_list != NULL)
	{
		while (p_temp != NULL)
		{
			if (p_temp->data != NULL)
			{
				ft_putstr(p_temp->data);
				if (i == 1)
					ft_putchar('\n');
			}
			p_temp = p_temp->p_next;
		}
	}
	return (0);
}
