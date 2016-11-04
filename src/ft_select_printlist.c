/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_printlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:15:44 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/04 14:57:15 by tbayet           ###   ########.fr       */
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
	if ((dims->x = width / (dims->maxlen + 2) - 2) < 0)
		dims->x = 0;
	dims->y = (dims->x) ? nbelems / dims->x: 0;
	if (nbelems % dims->x > 0)
		dims->y++;
	dims->x = nbelems / dims->y;
	if (nbelems % dims->y)
		dims->x++;
	dims->pos = -1;
	dims->size = nbelems;
	dims->scroll = 0;
	return (dims);
}

t_ldim			*ft_select_printlist(char **list, int nbelems, t_termcaps *tc, t_ldim *dims)
{
	int	x;
	int	y;

	if (!dims)
		dims = getdims(list, nbelems, tc->whidth);
//	printf("== {%d} {%d} [%d] (%d)\n", tc->whidth, dims->maxlen, dims->size, dims->x);
	y = 0;
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
		//	printf("[%s] [%d] [%d]\n", list[y + dims->scroll + (x * dims->y)], y + dims->scroll + (x * dims->y), x);
			ft_putspc(list[y + dims->scroll + (x * dims->y)], dims->maxlen, 1);
			if (dims->pos == y + dims->scroll + (x * dims->y))
				ft_putstr_fd(tc->me, 1);
			x++;
		}
		y++;
	}
	while (y)
	{
		ft_putstr_fd(tc->sr, 1);
		y--;
	}
	return (dims);
}
