/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup_plusone_del.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:28:44 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/19 11:31:53 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup_plusone_del(char **buft, char *buf)
{
	char	**tabcpy;
	int		i;

	i = 0;
	while (buft != NULL && buft[i] != NULL)
		i++;
	if (i == 0 || (tabcpy = (char**)malloc(sizeof(char*) * (i + 2))) == NULL)
		return (NULL);
	i = 0;
	while (buft != NULL && buft[i] != NULL)
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
	tabcpy[i++] = ft_strdup(buf);
	tabcpy[i] = NULL;
	ft_free_tab(&buft);
	return (tabcpy);
}
