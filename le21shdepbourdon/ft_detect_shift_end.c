/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_shift_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:13:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 17:30:42 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_detect_shift_end(char *buffer)
{
	if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 49 &&
		buffer[3] == 59 && buffer[4] == 50 && buffer[5] == 70)
		return (1);
	return (0);
}
