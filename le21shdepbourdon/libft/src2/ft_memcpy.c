/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:41:24 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/13 08:57:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	a;
	char			*str_src;
	char			*str2_dest;

	a = 0;
	if (n == 0 || dest == src)
		return (dest);
	str_src = (char *)src;
	str2_dest = (char *)dest;
	while (a < n)
	{
		str2_dest[a] = str_src[a];
		a++;
	}
	return (dest);
}
