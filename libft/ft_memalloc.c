/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:54:02 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/08 11:07:23 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*v;
	unsigned char	*tmp;
	int				e;

	e = 0;
	v = (void*)malloc(size);
	tmp = (unsigned char*)v;
	while (size-- > 0)
		tmp[size] = 0;
	return (v);
}
