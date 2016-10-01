/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/01 16:44:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_list(t_dlist *p_list)
{
	t_node		*p_temp;
	t_node		*p_del;

	if (p_list != NULL)
	{
		p_temp = p_list->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del->data);
			free(p_del);
		}
		free(p_list);
	}
}

void		ft_delete_list2(t_dlist **p_list)
{
	t_node		*p_temp;
	t_node		*p_del;

	if (p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del->data);
			free(p_del);
		}
		(*p_list)->length = 0;
		(*p_list)->pos = 0;
		(*p_list)->p_head = NULL;
		(*p_list)->p_tail = NULL;
	}
}

void		ft_delete_list3(t_dlist **p_list)
{
	t_node		*p_temp;
	t_node		*p_del;

	if (p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del->data);
			free(p_del);
		}
	}
}
