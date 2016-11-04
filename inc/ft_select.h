/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:09:58 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/04 16:23:48 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "minishell.h"
# include "autocompletion.h"
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

int				is_spec_separator(char c);
char			*ft_select(char **list, int nbelems, t_termcaps *tc);
void			ft_select_cancel(char **list, t_termcaps *tc);
char			*ft_select_get(char **list, t_termcaps *tc, char **line);
void			ft_select_move(char **list, char dir, t_termcaps *tc);
t_ldim			*ft_select_printlist(char **list, int nbelems,
	t_termcaps *tc, t_ldim *dims);
void			ft_select_move_up(t_ldim *dims);
void			ft_select_move_down(t_ldim *dims);
void			ft_select_move_left(t_ldim *dims);
void			ft_select_move_right(t_ldim *dims);

#endif
