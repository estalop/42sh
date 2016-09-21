/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separate_dot_coma.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 11:11:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 16:26:54 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_get_str(char *tab3, char *str, int mem, int index)
{
	int		index2;
	int		alpha;

	alpha = 0;
	index2 = 0;
	while (index2 < mem)
		index2++;
	while (index2 < index)
	{
		tab3[alpha] = str[index2];
		alpha++;
		index2++;
	}
	tab3[alpha] = '\0';
	return (tab3);
}

char		**ft_separate_dot_coma(char **tab3, char *line, int total)
{
	int		index;
	int		mem;
	int		compteur;

	index = 0;
	mem = 0;
	compteur = 0;
	tab3 = malloc(sizeof(char *) * total);
	while (line[index] != '\0')
	{
		if (line[index] == ';')
		{
			tab3[compteur] = malloc(sizeof(char) * index - mem + 1);
			tab3[compteur] = ft_get_str(tab3[compteur], line, mem, index);
			compteur++;
			mem = index + 1;
		}
		index++;
	}
	tab3[compteur] = malloc(sizeof(char) * index - mem + 1);
	tab3[compteur] = ft_get_str(tab3[compteur], line, mem, index);
	return (tab3);
}
