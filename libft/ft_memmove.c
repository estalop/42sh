/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:40:27 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/07 15:22:01 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			e;

	if (src == NULL || dst == NULL)
		return (dst);
	e = 0;
	str = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (dst < src)
		while (e < len)
		{
			str[e] = str2[e];
			e++;
		}
	else
		while (len-- > 0)
			str[len] = str2[len];
	return (dst);
}
