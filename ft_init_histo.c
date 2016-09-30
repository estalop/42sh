/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_histo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:23:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:24 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_histo(t_prstruct *proc)
{
	t_dlist		*histo;

	histo = NULL;
	histo = dlist_new(histo);
	ft_get_history_from_file(histo, open(ft_strjoin("/nfs/2015/p/pbourdon/", "/.42sh"),
		O_RDONLY), 0, 0);
	proc->histo2 = histo;
}
