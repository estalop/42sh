/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 18:07:02 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/03 18:25:15 by tbayet           ###   ########.fr       */
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
		free(list);
	list = NULL;
	ft_putstr_fd(tc->sf, 1);
	ft_putstr_fd(tc->cd, 1);
	ft_putstr_fd(tc->sr, 1);
}

char			*ft_select_get(char **list, t_termcaps *tc, char **line)
{
	char	*res;
	char	*newwline;
	char	*ptr;
	int		i;

	if (!dims || !list)
		return (NULL);
	i = tc->x - 11;
	i--;
	while ((*line)[i] != ' ' && (*line)[i] != '	')
		i--;
	if (!(newwline = ft_strnew(ft_strlen(*line) - (tc->x - 11 - i))))
		return (NULL);
	newwline = ft_strncpy(*line, newwline, i);
	res = list[dims->pos];
	ptr = newwline + i;
	ptr = ft_strcpy(res, ptr);
	ptr = newwline + i + ft_strlen(res);
	ptr = ft_strcpy((*line) + (tc->x - 11), ptr);
	ft_select_cancel(list, tc);
	//WTF MAN
	return (res);
}

//dir = U (up) | D (Down | L (left) | R (right)
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
