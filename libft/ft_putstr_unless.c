/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_unless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:29:01 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:29:02 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putstr_unless(const char *format, char *c)
{
	int n;

	if (!c)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	n = c - format;
	if (!format || n < 0)
		return (0);
	while (n-- && format[n])
		;
	if (n == -1 && *format)
	{
		n = c - format;
		write(1, format, n);
	}
	else
	{
		ft_putstr(format);
		n = ft_strlen(format);
	}
	return (n);
}
