/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:07:02 by tbayet            #+#    #+#             */
/*   Updated: 2016/10/06 20:32:01 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "autocompletion.h"

static	t_dim	dimensions;

static void		sighandler_resize(int sig)
{
	dimensions.x = ;
	dimensions.y = ;
}

void			ft_select(char **list, int nbelems, t_termcaps *tc)
{
	signal(SIGWINCH, sighandler_resize);
	if (tc && nbelems)
	{
		if (nbelems > MAX_NB_AFF)
		{
			ft_putstr_fd(tgoto);
			ft_putstr_fd("Afficher");
			ft_putstr_fd(nbelems);
			ft_putstr_fd("elements ?")
				Y or NO ?;
	}
}
