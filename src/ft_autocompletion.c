/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompletion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:05:55 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/03 15:56:35 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

char	*ft_autocomp(t_termcaps *cap, char *str)
{
	if (cap->exec == 0)
	{
		if ((cap->autotab = autocompletion(str, cap->x - 11, cap->bin, "./")))
		{
			ft_select(cap->autotab, ft_tablen(cap->autotab), cap);
			cap->exec = 1;
		}
	}
	else
	{
		ft_select_move(cap->autotab, 'B', cap);
		cap->exec = 2;
	}
	return (str);
}

