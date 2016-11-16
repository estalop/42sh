/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_printlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:15:44 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/16 16:05:27 by tbayet           ###   ########.fr       */
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
	dims->y = (dims->x) ? nbelems / dims->x: 0;
	if (nbelems % dims->x > 0)
		(dims->y)++;
	dims->x = nbelems / dims->y;
	if (nbelems % dims->y)
		(dims->x)++;
	dims->pos = -1;
	dims->size = nbelems;
	dims->scroll = 0;
	return (dims);
}

t_ldim			*ft_select_printlist(char **list, t_termcaps *tc, t_ldim *dims, char *line)
{
	int	x;
	int	y;
	int	save;

	if (!dims)
		dims = getdims(list, ft_tablen(list), tc->whidth);
	if (!dims)
			return (NULL);
	y = 0;
	save = ft_end(tc, line, ft_strlen(line) + tc->neg);
	ft_putstr_fd(tc->sf, 1);
	ft_putstr_fd(tc->cd, 1);
	ft_putstr_fd(tc->sr, 1);
	while (y < dims->y && y < MAX_SELECT_LINES)
	{
		x = 0;
		ft_putstr_fd(tc->sf, 1);
		while (x < dims->x && (y + dims->scroll + (x * dims->y)) < dims->size)
		{
			ft_putstr_fd(tgoto(tc->cv, 0, x * (dims->maxlen + 2)), 1);
			if (dims->pos == y + dims->scroll + (x * dims->y))
				ft_putstr_fd(tc->mr, 1);
			ft_putspc(list[y + dims->scroll + (x * dims->y)], dims->maxlen, 1);
			if (dims->pos == y + dims->scroll + (x * dims->y))
				ft_putstr_fd(tc->me, 1);
			x++;
		}
		y++;
	}
	while ((y + save))
	{
		ft_putstr_fd(tc->sr, 1);
		y--;
	}
	save = ft_calculate_whidth(line, tc->x, tc);
	ft_putstr_fd(tgoto(tc->cv, 0, save), 1);
	return (dims);
}
