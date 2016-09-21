/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 00:58:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/16 00:58:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_delete_tab(char *str)
{
	char	*tmp;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	tmp = ft_memalloc(ft_strlen(str) + 1);
	while (str[index] != '\0' && (str[index] == ' ' || str[index] == '\t'))
		index++;
	while (str[index] != '\0')
	{
		if (str[index] == '\t')
			tmp[index2++] = ' ';
		else
			tmp[index2++] = str[index];
		index++;
	}
	tmp[index2] = '\0';
	return (tmp);
}
