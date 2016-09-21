/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 00:31:21 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/18 18:03:52 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int index)
{
	char		*tmp;
	int			index2;

	index2 = 0;
	tmp = malloc(sizeof(char) * index);
	while (index2 < index)
	{
		tmp[index2] = str[index2];
		index2++;
	}
	tmp[index2] = '\0';
	return (tmp);
}
