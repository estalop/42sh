/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:11:57 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/08 11:08:32 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			e;

	e = 0;
	str = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	while (e < n)
	{
		str[e] = str2[e];
		if (str2[e] == c)
			return (&dst[e + 1]);
		e++;
	}
	return (NULL);
}
