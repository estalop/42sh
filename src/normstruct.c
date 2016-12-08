/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:25:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/12/08 17:49:46 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*msga2(t_dlist *p_list, t_node *p_new, int i)
{
	if (i == 0)
	{
		p_new->p_prev = NULL;
		p_list->p_head = p_new;
		p_list->p_tail = p_new;
	}
	else
	{
		p_list->p_head->p_prev = p_new;
		p_new->p_next = p_list->p_head;
		p_list->p_head = p_new;
	}
	return (p_list);
}

t_dlist		*msga3(t_dlist *p_list, t_node *p_new, int i)
{
	if (i == 0)
	{
		p_new->p_prev = NULL;
		p_list->p_head = p_new;
		p_list->p_tail = p_new;
	}
	else
	{
		p_list->p_tail->p_next = p_new;
		p_new->p_prev = p_list->p_tail;
		p_list->p_tail = p_new;
	}
	return (p_list);
}
