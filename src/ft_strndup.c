/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:01:57 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/30 18:44:50 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//WTF
char	*ft_strndup(const char *s1, size_t n)
{
	unsigned int	cpt;
	char			*s2;

	cpt = 0;
	s2 = (char*)malloc(sizeof(char) * (n + 1));
	while ((s1[cpt] != '\0') && (cpt < n))
	{
		s2[cpt] = s1[cpt];
		cpt++;
	}
	s2[cpt] = '\0';
	return (s2);
}
