/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_and_end_anx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:52:37 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/03 18:02:26 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

int		ft_out_anx(char **tmp, t_termcaps *cap)
{
	if (cap->cmd)
		*tmp = ft_select_get(cap->autotab, cap, &(cap->cmd));
	else if (cap->str)
		*tmp = ft_select_get(cap->autotab, cap, &(cap->str));
	else
	{
		cap->str = ft_select_get(cap->autotab, cap, NULL);
		*tmp = cap->str;
	}
	if (!*tmp)
		return (1);
	cap->exec = 0;
	return (0);
}

void	ft_out_anx_b(char *buf, char **tmp, t_termcaps *cap)
{
	if (buf[0] == 12)
		ft_putstr(cap->prom);
	if (buf[0] == 10)
	{
		ft_end(cap, *tmp, ft_strlen(*tmp) + cap->neg);
		tputs(cap->sf, 0, ft_output);
		tputs(cap->cr, 0, ft_output);
	}
}
