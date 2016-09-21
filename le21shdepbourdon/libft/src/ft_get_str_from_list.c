/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str_from_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 21:17:25 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:52:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_get_str_from_list(t_dlist *list)
{
	int		index;
	int		pos;
	char	*str;

	pos = 1;
	index = 0;
	str = ft_strnew(list->length);
	while (pos <= list->length)
	{
		str[index] = ft_get_element_from_list(list, pos)[0];
		index++;
		pos++;
	}
	return (str);
}
