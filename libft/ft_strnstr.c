/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:57:43 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/16 18:11:18 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	if (!s1 || !s2)
		return (NULL);
	if (!s2[0])
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s2[0] == s1[i])
		{
			j = 0;
			while (s1[i + j] && s2[j] == s1[i + j] && i + j < n)
				j++;
			if (!s2[j])
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
