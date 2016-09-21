/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_second_delete.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:26:06 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 14:34:32 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_detect_second_delete(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 51 &&
		buffer[3] == 126 && buffer[4] == 0 && buffer[5] == 0)
		return (1);
	return (0);
}
