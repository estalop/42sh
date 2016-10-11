/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:34:26 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:34:40 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wctomb(char *s, int wc, int l)
{
	static unsigned int mask[] = {49280, 14712960, 4034953344};

	if (l == 1)
		*s = wc;
	else if (l == 2)
	{
		*s = (mask[0] >> 8) | (wc >> 6);
		*(++s) = (mask[0] & 0xFF) | (wc & 0x3F);
	}
	else if (l == 3)
	{
		*s = (mask[1] >> 16) | (wc >> 12);
		*(++s) = (mask[1] & 0xFF) | ((wc >> 6) & 0x3F);
		*(++s) = (mask[1] & 0xFF) | (wc & 0x3F);
	}
	else
	{
		*s = (mask[2] >> 24) | ((wc >> 18) & 0x07);
		*(++s) = (mask[2] & 0xFF) | ((wc >> 12) & 0x3F);
		*(++s) = (mask[2] & 0xFF) | ((wc >> 6) & 0x3F);
		*(++s) = (mask[2] & 0xFF) | (wc & 0x3F);
	}
}
