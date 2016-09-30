/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:06:21 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/30 11:13:14 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			t;
	unsigned char	*str;
	unsigned char	uc;

	uc = (unsigned char)c;
	t = 0;
	str = (unsigned char*)s;
	while (t < n)
	{
		if (str[t] == uc)
			return (void*)(&s[t]);
		t++;
	}
	return (NULL);
}
