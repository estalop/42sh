/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:23:41 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/13 08:59:35 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t		a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

size_t		l(const char *str)
{
	size_t		a;

	a = 0;
	while (str[a] != '\0')
		a++;
	a++;
	return (a);
}
