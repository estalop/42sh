/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:17:01 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/26 20:09:50 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	if (c == 0)
		return (char*)(&s[i]);
	while (i > 0)
	{
		if (s[i] == c)
		{
			return (char*)(&s[i]);
		}
		i--;
	}
	if (s[i] == c)
		return (char*)(&s[i]);
	return (NULL);
}
