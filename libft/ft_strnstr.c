/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:57:43 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/27 17:30:15 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
		j++;
	if (j == 0)
		return (char *)(s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s1[i + j] != '\0' && i + j < n)
			{
				j++;
				if (s2[j] == '\0')
					return (char *)(&s1[i]);
			}
		}
		i++;
	}
	return (NULL);
}
