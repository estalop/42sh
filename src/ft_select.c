/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:07:02 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/23 14:04:53 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_select.h"

static t_ldim	*dims = NULL;

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

	if (dims)
		free(dims);
	dims = NULL;
	if (list)
		ft_deltab(list);
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
	char	*res;
	char	*newwline;
	char	*ptr;
	char	*escape;
	int		i;

	if (!dims || !list)
		return (NULL);
	if (!(line))
	{
		if (!(escape = ft_strdup("")))
			return (NULL);
		line = &escape;
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
	ft_select_cancel(list, tc, *line);
	ft_thome(tc, *line);
	tputs(tc->cd, 1, ft_output);
	ft_newputstr(newwline, tc);
	tc->x = tc->prompt + ft_strlen(newwline);
	ft_thome(tc, newwline);
	free(*line);
	*line = newwline;
	tc->x = i + ft_strlen(res)  + tc->prompt;
	return (newwline);
}

void			ft_select_move(char **list, char dir, t_termcaps *tc, char *line)
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
		ft_select_printlist(list, tc, dims, line);
	}
}

char			*ft_select(char **list, t_termcaps *tc, char *line)
{
	if (!dims)
		dims = ft_select_print(list, tc, line);
	else
		dims = ft_select_printlist(list, tc, dims, line);
	return (NULL);
}
