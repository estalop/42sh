/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_histo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:23:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/05 12:56:32 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_histo(t_prstruct *proc, t_termcaps *cap)
{
	t_dlist		*histo;
	char		*str;

	histo = NULL;
	histo = dlist_new(histo);
	if (ft_get_home(proc->env[2]) != NULL)
	{
		str = ft_strjoin(ft_get_home(proc->env[2]), "/.42sh");
		ft_get_history_from_file(histo, open(str, O_RDONLY), 0, 0);
		free(str);
	}
	else
	{
		ft_putstr("The history file is not available. Please set the home");
		ft_putstr(" env variable\n");
	}
	proc->histo2 = histo;
	cap->histo2 = histo;
}
