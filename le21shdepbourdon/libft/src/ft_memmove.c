/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:47:31 by tfleming          #+#    #+#             */
/*   Updated: 2016/08/14 18:50:49 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *source, size_t len)
{
	char	copy[len];

	ft_memcpy(copy, source, len);
	ft_memcpy(dest, copy, len);
	return (dest);
}
