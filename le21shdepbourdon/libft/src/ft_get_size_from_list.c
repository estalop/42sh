/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:13:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 12:42:10 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_size_from_list(t_dlist *p_list)
{
	t_node			*p_temp;
	unsigned long	top;

	top = 0;
	p_temp = p_list->p_head;
	if (p_list != NULL)
	{
		while (p_temp != NULL)
		{
			if (p_temp->data != NULL)
			{
				if (top < ft_strlen(p_temp->data))
					top = ft_strlen(p_temp->data);
			}
			p_temp = p_temp->p_next;
		}
	}
	return (top);
}
