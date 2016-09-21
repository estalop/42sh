/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:11:57 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:05:19 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	char			*strr;
	size_t			e;

	e = 0;
	str = dst;
	strr = (char*)src;
	while (e < n)
	{
		str[e] = strr[e];
		if (strr[e] == c)
			return (&dst[e + 1]);
		e++;
	}
	return (NULL);
}
