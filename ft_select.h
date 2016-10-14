/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:09:58 by tbayet            #+#    #+#             */
/*   Updated: 2016/10/14 14:29:40 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT

# include "minishell.h"
# define MAX_SELECT_LINES 8

typedef struct	s_ldim
{
	int			x;
	int			y;
	int			pos;
	int			size;
	int			scroll;
	int			maxlen;
}				t_ldim;


void			ft_select_cancel(char **list, t_termcaps *tc);
char			*ft_select_get(char **list, t_termcaps *tc);
void			ft_select_move(char **list, char dir, t_termcaps *tc);
t_ldim			*ft_select_printlist(char **list, int nbelems, t_termcaps *tc, t_ldim *dims);
void			ft_select_move_up(t_ldim *dims);
void			ft_select_move_down(t_ldim *dims);
void			ft_select_move_left(t_ldim *dims);
void			ft_select_move_right(t_ldim *dims);

#endif
