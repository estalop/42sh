/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:13:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/12/05 09:57:04 by jbobin           ###   ########.fr       */
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
	return (1);
}

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
	return (0);
}

int		ft_display_list4(t_dlist *p_list, int limit)
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
				if (p_list->length - index <= limit)
				{
					ft_putnbr(index);
					ft_putchar(' ');
					ft_putstr(p_temp->data);
					ft_putchar('\n');
				}
				index++;
			}
			p_temp = p_temp->p_next;
		}
	}
	return (1);
}
