/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:35:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/14 15:41:17 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*dlist_new(t_dlist *p_new)
{
	p_new = malloc(sizeof(t_dlist));
	if (p_new != NULL)
	{
		p_new->length = 0;
		p_new->pos = 1;
		p_new->index2 = 0;
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return (p_new);
}
