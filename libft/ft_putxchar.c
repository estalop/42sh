/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:29:27 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:29:31 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putxchar(char c, int l)
{
	char *s;

	if (!l || !(s = ft_memalloc(l)))
		return ;
	ft_memset(s, (int)c, l);
	write(1, s, l);
	free(s);
}
