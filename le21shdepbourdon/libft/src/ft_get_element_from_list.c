/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 18:39:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 16:36:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_element_from_list(t_dlist *liste, int pos)
{
	int			i;
	t_node		*courant;

	if (pos <= 0 || pos > liste->length)
		return (NULL);
	i = 1;
	courant = liste->p_head;
	while (i++ < pos && courant && i <= liste->length)
		courant = courant->p_next;
	return (courant->data);
}
