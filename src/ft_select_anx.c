/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_anx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:30:54 by tviviand          #+#    #+#             */
/*   Updated: 2016/12/08 17:39:33 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

int	ft_select_get_anx(t_selectget *s, char **line, char **list, t_termcaps *tc)
{
	if (!(s->newwline = ft_strnew(ft_strlen(*line) -
	(tc->x - tc->prompt - s->i) + ft_strlen(s->res))))
		return (1);
	s->newwline = ft_strncpy(s->newwline, *line, s->i);
	s->ptr = s->newwline + s->i;
	s->ptr = ft_strcpy(s->ptr, s->res);
	s->ptr = s->newwline + s->i + ft_strlen(s->res);
	s->ptr = ft_strcpy(s->ptr, (*line) + (tc->x - tc->prompt));
	ft_select_cancel(list, tc, *line);
	ft_thome(tc, *line);
	tputs(tc->cd, 1, ft_output);
	ft_newputstr(s->newwline, tc);
	tc->x = tc->prompt + ft_strlen(s->newwline);
	ft_thome(tc, s->newwline);
	free(*line);
	*line = s->newwline;
	tc->x = s->i + ft_strlen(s->res) + tc->prompt;
	return (0);
}
