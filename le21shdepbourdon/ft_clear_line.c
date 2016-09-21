/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_n_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:39:19 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/04 22:46:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_clear_line(void)
{
	char	*res;

	if ((res = tgetstr("dl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_putchar2);
	return (0);
}
