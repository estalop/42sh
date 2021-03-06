/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element_from_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:39:12 by pbourdon          #+#    #+#             */
/*   Updated: 2017/01/04 09:01:00 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_element_from_list(t_dlist *liste, int pos)
{
	int			i;
	t_node		*courant;

	if (pos < 0)
		pos = liste->length + pos;
	if (pos < 0 || pos > liste->length - 1)
		return (NULL);
	i = 0;
	courant = liste->p_head;
	while (i++ < pos && courant && i < liste->length)
		courant = courant->p_next;
	return (courant->data);
}
