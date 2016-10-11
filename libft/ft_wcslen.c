/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:34:21 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:34:22 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen(const int *wcs)
{
	int n;

	n = 0;
	while (*wcs != L'\0')
	{
		n += ft_wcscbytes(ft_binsize(*wcs));
		wcs++;
	}
	return (n);
}
