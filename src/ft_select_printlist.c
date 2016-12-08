/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_printlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:15:44 by tbayet            #+#    #+#             */
/*   Updated: 2016/12/08 16:34:43 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_putspc(char *str, int min, int fd)
{
	int		len;
	char	c;

	if (str)
	{
		c = ' ';
		len = ft_strlen(str);
		write(fd, str, len);
		while (len < min)
		{
			write(fd, &c, 1);
			len++;
		}
	}
}

static void		getdims_anx(t_ldim *dims, int nbelems)
{
	dims->y = (dims->x) ? nbelems / dims->x : 0;
	if (nbelems % dims->x > 0)
		(dims->y)++;
	dims->x = nbelems / dims->y;
	if (nbelems % dims->y)
		(dims->x)++;
	dims->pos = -1;
	dims->size = nbelems;
	dims->scroll = 0;
}

static t_ldim	*getdims(char **list, int nbelems, int width)
{
	t_ldim	*dims;
	int		len;
	int		i;

	if (!(dims = (t_ldim*)malloc(sizeof(t_ldim))))
		return (NULL);
	i = 0;
	dims->maxlen = 0;
	while (list[i])
	{
		if ((len = ft_strlen(list[i])) > dims->maxlen)
			dims->maxlen = len;
		i++;
	}
	if ((dims->x = (width - 2) / (dims->maxlen + 2)) < 0)
		dims->x = 0;
	if (dims->x == 0)
	{
		free(dims);
		return (NULL);
	}
	getdims_anx(dims, nbelems);
	return (dims);
}

static void		ft_select_printlist_anx(t_selprintlist *t)
{
	while (t->y < t->dims->y && t->y < MAX_SELECT_LINES)
	{
		t->x = 0;
		ft_putstr_fd(t->tc->sf, 1);
		while (t->x < t->dims->x &&
			(t->y + t->dims->scroll + (t->x * t->dims->y)) < t->dims->size)
		{
			ft_putstr_fd(tgoto(t->tc->cv, 0, t->x * (t->dims->maxlen + 2)), 1);
			if (t->dims->pos == t->y + t->dims->scroll + (t->x * t->dims->y))
				ft_putstr_fd(t->tc->mr, 1);
			ft_putspc(t->list[t->y + t->dims->scroll + \
				(t->x * t->dims->y)], t->dims->maxlen, 1);
			if (t->dims->pos == t->y + t->dims->scroll + (t->x * t->dims->y))
				ft_putstr_fd(t->tc->me, 1);
			t->x++;
		}
		t->y++;
	}
	while ((t->y + t->save))
	{
		ft_putstr_fd(t->tc->sr, 1);
		t->y--;
	}
	t->save = ft_calculate_whidth(t->line, t->tc->x, t->tc);
	ft_putstr_fd(tgoto(t->tc->cv, 0, t->save), 1);
}

t_ldim			*ft_select_printlist(char **list, t_termcaps *tc, t_ldim *dims,
	char *line)
{
	t_selprintlist	t;
	int				x;
	int				y;
	int				save;

	if (!dims && !(dims = getdims(list, ft_tablen(list), tc->whidth)))
		return (NULL);
	y = 0;
	save = ft_end(tc, line, ft_strlen(line) + tc->neg);
	ft_putstr_fd(tc->sf, 1);
	ft_putstr_fd(tc->cd, 1);
	ft_putstr_fd(tc->sr, 1);
	x = 0;
	t.x = x;
	t.y = y;
	t.save = save;
	t.list = list;
	t.tc = tc;
	t.dims = dims;
	t.line = line;
	ft_select_printlist_anx(&t);
	return (dims);
}
