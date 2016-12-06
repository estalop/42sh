/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:09:58 by tbayet            #+#    #+#             */
/*   Updated: 2016/12/06 20:41:49 by tviviand         ###   ########.fr       */
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

typedef struct		s_selprintlist
{
	int				x;
	int				y;
	int				save;
	char			**list;
	t_termcaps		*tc;
	t_ldim			*dims;
	char			*line;
}					t_selprintlist;

int				is_spec_separator(char c);
char			*ft_select(char **list, t_termcaps *tc, char *line);
void			ft_select_cancel(char **list, t_termcaps *tc, char *line);
char			*ft_select_get(char **list, t_termcaps *tc, char **line);
void			ft_select_move(char **list, char dir, t_termcaps *tc, \
	char *line);
t_ldim			*ft_select_printlist(char **list, t_termcaps *tc, \
	t_ldim *dims, char *line);
void			ft_select_move_up(t_ldim *dims);
void			ft_select_move_down(t_ldim *dims);
void			ft_select_move_left(t_ldim *dims);
void			ft_select_move_right(t_ldim *dims);

#endif
