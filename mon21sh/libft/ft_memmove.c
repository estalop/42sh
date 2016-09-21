/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:40:27 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/27 11:32:39 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_cp(char *o, size_t len)
{
	size_t		i;
	char		*cp;

	i = 0;
	cp = (char *)malloc(sizeof(char) * len);
	if (cp == NULL)
		return (cp);
	while (i < len)
	{
		cp[i] = o[i];
		i++;
	}
	return (cp);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	char			*strr;
	size_t			e;

	e = 0;
	strr = ft_cp((char*)src, len);
	if (src == NULL)
		return (dst);
	str = dst;
	while (e < len)
	{
		str[e] = strr[e];
		e++;
	}
	free(strr);
	return (dst);
}
