/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:12:26 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:09:02 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
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
		e++;
	}
	return (dst);
}
