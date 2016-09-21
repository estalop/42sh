/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_arrows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:12:33 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 12:08:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_detect_up(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65 &&
		buf[3] == 0 && buf[4] == 0 && buf[5] == 0)
		return (1);
	else
		return (0);
}

int		ft_detect_down(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66 &&
		buf[3] == 0 && buf[4] == 0 && buf[5] == 0)
		return (1);
	else
		return (0);
}

int		ft_detect_left(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68 &&
		buf[3] == 0 && buf[4] == 0 && buf[5] == 0)
		return (1);
	else
		return (0);
}

int		ft_detect_right(char *buf)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67 &&
		buf[3] == 0 && buf[4] == 0 && buf[5] == 0)
		return (1);
	else
		return (0);
}
