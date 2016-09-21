/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup_plusone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 12:56:09 by jbobin            #+#    #+#             */
/*   Updated: 2016/04/27 14:52:10 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabdup_plusone(char **buft, char *buf)
{
	char	**tabcpy;
	int		i;

	i = 0;
	while (buft != NULL && buft[i] != NULL)
		i++;
	if (i == 0 || (tabcpy = (char**)malloc(sizeof(char*) * (i + 2))) == NULL)
		return (NULL);
	tabcpy[i + 1] = NULL;
	tabcpy[i] = ft_strdup(buf);
	i = 0;
	while (tabcpy[i] != NULL)
	{
		tabcpy[i] = ft_strdup(buft[i]);
		if (tabcpy[i] == NULL)
		{
			while (i-- > 0)
				ft_strdel(&tabcpy[i]);
			free(tabcpy);
			return (NULL);
		}
		i++;
	}
	return (tabcpy);
}
