/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:09:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/11 16:10:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*nzone;

	if (!size)
		return (NULL);
	nzone = (void *)malloc(sizeof(void*) * size);
	if (!nzone)
		return (NULL);
	ft_bzero(nzone, size);
	return (nzone);
}
