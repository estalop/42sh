/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:38:44 by jbobin            #+#    #+#             */
/*   Updated: 2016/04/08 13:50:32 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabdup(char **buf)
{
	char	**tabcpy;
	int		i;

	i = 0;
	if (buf == NULL)
		return (NULL);
	while (buf[i] != NULL)
		i++;
	if (i == 0 || (tabcpy = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	tabcpy[i] = NULL;
	i = 0;
	while (buf[i] != NULL)
	{
		tabcpy[i] = ft_strdup(buf[i]);
		if (tabcpy[i] == NULL)
		{
			while (--i > 0)
				ft_strdel(&tabcpy[i]);
			free(tabcpy);
			return (NULL);
		}
		i++;
	}
	return (tabcpy);
}
