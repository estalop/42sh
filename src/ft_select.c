/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:07:02 by tbayet            #+#    #+#             */
/*   Updated: 2016/12/12 18:01:00 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

t_ldim			*g_dims = NULL;

static t_ldim	*ft_select_print(char **list, t_termcaps *tc, char *line)
{
	int		nbelems;

	nbelems = ft_tablen(list);
	if (tc && nbelems)
		return (ft_select_printlist(list, tc, NULL, line));
	return (NULL);
}

void			ft_select_cancel(char **list, t_termcaps *tc, char *line)
{
	int	save;

	if (g_dims)
		free(g_dims);
	g_dims = NULL;
	if (list)
		ft_free_tab(&list);
	list = NULL;
	save = ft_end(tc, line, ft_strlen(line) + tc->neg);
	ft_putstr_fd(tc->sf, 1);
	ft_putstr_fd(tc->cd, 1);
	ft_putstr_fd(tc->sr, 1);
	while (save > 0)
	{
		ft_putstr_fd(tc->sr, 1);
		save--;
	}
	save = ft_calculate_whidth(line, tc->x, tc);
	ft_putstr_fd(tgoto(tc->cv, 0, save), 1);
}

char			*ft_select_get(char **list, t_termcaps *tc, char **line)
{
	t_selectget	s;

	s.res = NULL;
	s.newwline = NULL;
	s.ptr = NULL;
	if (!(s.i = 0) && (!g_dims || !list))
		return (NULL);
	if (!(s.escape = NULL) && !(line))
	{
		if (!(s.escape = ft_strdup("")))
			return (NULL);
		line = &s.escape;
	}
	//is.i = tc->x - tc->prompt;
	s.i = tc->x - tc->neg;
	if ((--s.i) < 0)
		s.i = 0;
	while (s.i && (*line)[s.i] != ' ' && (*line)[s.i] != '	' &&
	(*line)[s.i] != '/' && !is_spec_separator((*line)[s.i]))
		s.i--;
	s.i = (s.i) ? s.i + 1 : 0;
	s.res = list[g_dims->pos];
	if (ft_select_get_anx(&s, line, list, tc))
		return (NULL);
	else
		return (s.newwline);
}

void			ft_select_move(char **list, char dir,
	t_termcaps *tc, char *line)
{
	if (g_dims)
	{
		if (dir == 'A')
			ft_select_move_up(g_dims);
		else if (dir == 'B')
			ft_select_move_down(g_dims);
		else if (dir == 'D')
			ft_select_move_left(g_dims);
		else if (dir == 'C')
			ft_select_move_right(g_dims);
		ft_select_printlist(list, tc, g_dims, line);
	}
}

char			*ft_select(char **list, t_termcaps *tc, char *line)
{
	if (!g_dims)
		g_dims = ft_select_print(list, tc, line);
	else
		g_dims = ft_select_printlist(list, tc, g_dims, line);
	return (NULL);
}
