/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:07:02 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/09 13:47:52 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

static t_ldim	*dims = NULL;

static t_ldim	*ft_select_print(char **list, int nbelems, t_termcaps *tc)
{
	char	buf[4];

	if (tc && nbelems)
	{
		if (nbelems > MAX_NB_AFF)
		{
			ft_putstr_fd(tc->sf, 1);
			ft_putstr_fd("42sh: do you wish to see all ", 1);
			ft_putnbr_fd(nbelems, 1);
			ft_putstr_fd(" possibilities ?", 1);
			ft_bzero(buf, 4);
			while (read(0, buf, 3) == 0);
			ft_putstr_fd(tgoto(tc->cv, 0, 0), 1);
			ft_putstr_fd(tc->cd, 1);
			ft_putstr_fd(tc->sr, 1);
		//	if (!ft_strcmp(buf, "yes") && !ft_strcmp(catch, "tab"))
		//		return (1);
		}
		return (ft_select_printlist(list, nbelems, tc, NULL));
	}
	return (NULL);
}

void			ft_select_cancel(char **list, t_termcaps *tc)
{
	if (dims)
		free(dims);
	dims = NULL;
	if (list)
		ft_deltab(list);
	list = NULL;
	ft_putstr_fd(tc->sf, 1);
	ft_putstr_fd(tc->cd, 1);
	ft_putstr_fd(tc->sr, 1);
	ft_putstr_fd(tgoto(tc->cv, 0, tc->x), 1);
}

char			*ft_select_get(char **list, t_termcaps *tc, char **line)
{
	char	*res;
	char	*newwline;
	char	*ptr;
	int		i;

	if (!dims || !list)
		return (NULL);
	if (!(*line))
	{
		tc->x = ft_strlen(list[dims->pos]) + tc->prompt;
		res = ft_strdup(list[dims->pos]);
		ft_select_cancel(list, tc);
		return (res);
	}
	i = tc->x - tc->prompt;
	if ((--i) < 0)
		i = 0;
	while (i && (*line)[i] != ' ' && (*line)[i] != '	' && (*line)[i] != '/' && !is_spec_separator((*line)[i]))
		i--;
	i = (i) ? i + 1: 0;
	res = list[dims->pos];
	if (!(newwline = ft_strnew(ft_strlen(*line) - (tc->x - tc->prompt - i) + ft_strlen(res))))
		return (NULL);
	newwline = ft_strncpy(newwline, *line, i);
	ptr = newwline + i;
	ptr = ft_strcpy(ptr, res);
	ptr = newwline + i + ft_strlen(res);
	ptr = ft_strcpy(ptr, (*line) + (tc->x - tc->prompt));
	tc->x = i + ft_strlen(res)  + tc->prompt;
	ft_select_cancel(list, tc);
	return (newwline);
}

void			ft_select_move(char **list, char dir, t_termcaps *tc)
{
	if (dims)
	{
		if (dir == 'A')
			ft_select_move_up(dims);
		else if (dir == 'B')
			ft_select_move_down(dims);
		else if (dir == 'D')
			ft_select_move_left(dims);
		else if (dir == 'C')
			ft_select_move_right(dims);
		ft_select_printlist(list, dims->size, tc, dims);
	}
}

char			*ft_select(char **list, int nbelems, t_termcaps *tc)
{
	if (!dims)
		dims = ft_select_print(list, nbelems, tc);
	else
		dims = ft_select_printlist(list, dims->size, tc, dims);
	return (NULL);
}
