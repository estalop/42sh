/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_avant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 01:03:44 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 14:12:41 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*fuck42(t_node *courant, char *data)
{
	t_node		*n;

	n = malloc(sizeof(*n));
	if (n != NULL)
	{
		n->data = ft_strdup(data);
		courant->p_next->p_prev = n;
		courant->p_prev->p_next = n;
		n->p_prev = courant->p_prev;
		n->p_next = courant;
	}
	return (courant);
}

t_dlist		*ins_avant(t_dlist *liste, char *data, t_node *courant, int pos)
{
	int			i;
	t_node		*n;

	if (pos < 1 || pos > liste->length)
		return (liste);
	i = 1;
	courant = liste->p_head;
	while (i++ < pos)
		courant = courant->p_next;
	n = malloc(sizeof(*n));
	if (n != NULL)
	{
		n->data = ft_strdup(data);
		n->p_prev = courant->p_prev;
		n->p_next = courant;
		if (courant->p_prev == NULL)
			liste->p_head = n;
		else
			courant->p_prev->p_next = n;
		courant->p_prev = n;
		liste->pos = liste->pos + 1;
		liste->length = liste->length + 1;
	}
	return (liste);
}
