/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_page_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:27:41 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/07 16:27:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_detect_page_down(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 54 &&
		buffer[3] == 126 && buffer[4] == 0 && buffer[5] == 0)
		return (1);
	return (0);
}
