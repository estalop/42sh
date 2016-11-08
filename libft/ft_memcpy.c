/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:12:26 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/08 09:55:25 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
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
		e++;
	}
	return (dst);
}
