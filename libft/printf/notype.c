/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notype.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:50:48 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 17:50:49 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		notype(t_argf *arg)
{
	char s[2];

	s[0] = *(arg->end);
	s[1] = 0;
	arg->end++;
	arg->flag[FL_SPCE] = FALSE;
	arg->precision = -1;
	return (print_integer(arg, s));
}
