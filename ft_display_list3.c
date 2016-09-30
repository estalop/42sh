/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:13:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/30 15:56:24 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_display_list3(t_dlist *p_list)
{
	t_node		*p_temp;
	int			index;

	index = 0;
	p_temp = p_list->p_head;
	if (p_list != NULL)
	{
		while (p_temp != NULL)
		{
			if (p_temp->data != NULL)
			{
				ft_putnbr(index);
				ft_putchar(' ');
				ft_putstr(p_temp->data);
				ft_putchar('\n');
				index++;
			}
			p_temp = p_temp->p_next;
		}
	}
	return (1);
}
