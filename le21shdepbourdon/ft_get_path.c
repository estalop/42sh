/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:28:18 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:47:28 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_get_path(char *arg)
{
	int		index;
	char	*tmp;
	int		index2;

	index = 3;
	index2 = 0;
	tmp = malloc(sizeof(char) * ft_strlen(arg));
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\r' ||
		arg[index] == '\n')
		index++;
	while (arg[index] != '\0' && arg[index] != ' ')
	{
		tmp[index2] = arg[index];
		index++;
		index2++;
	}
	tmp[index2] = '\0';
	return (tmp);
}
