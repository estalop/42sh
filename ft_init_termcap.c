/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_termcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:20:35 by jbobin            #+#    #+#             */
/*   Updated: 2016/07/15 08:58:50 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_output(int c)
{
	ft_putchar(c);
	return (0);
}

void	ft_init_termcap(t_termcaps *cap)
{
	char	*termtype;

	termtype = getenv("TERM");
	if (tgetent(cap->buf, "xterm-256color") < 0)
		if (tgetent(cap->buf, termtype) < 0)
			ft_putendl_fd("21sh: data not found", 2);
	if ((cap->height = tgetnum("li")) == 0 \
		|| (cap->whidth = tgetnum("co")) == 0 \
		|| !(cap->im = tgetstr("im", NULL))	  \
		|| !(cap->bl = tgetstr("bl", NULL))	\
		|| !(cap->sf = tgetstr("sf", NULL)) \
		|| !(cap->sr = tgetstr("sr", NULL)) \
		|| !(cap->cr = tgetstr("cr", NULL))	\
		|| !(cap->cv = tgetstr("ch", NULL)) \
		|| !(cap->dc = tgetstr("dl", NULL)) \
		|| !(cap->cl = tgetstr("cl", NULL)))
		ft_putendl_fd("21sh: can not use termcaps", 2);
	cap->mi = tgetflag("mi");
	termtype = tgetstr("pc", NULL);
	cap->pc = termtype ? *termtype : '\0';
	cap->auto_wrap = tgetflag("am");
	cap->auto_scroll = tgetflag("LP");
}

void	ft_reset_term(int signum)
{
	struct termios	term;

	if (tcgetattr(0, &term) != -1)
	{
		term.c_lflag |= (ECHO | ICANON);
		tcsetattr(0, 0, &term);
	}
	if (signum > 0)
		exit(0);
}

void	ft_set_term(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl_fd("21sh: mode error", 2);
		exit(1);
	}
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
}

t_plist	*ft_create_pipe(int num)
{
	t_plist	*list;
	t_plist	*o;
	int		i;

	if (num > 0)
	{
		o = (t_plist*)malloc(sizeof(t_plist));
		o->no = 0;
		o->next = NULL;
		pipe(o->pipe);
		i = 1;
		list = o;
		while (i < num)
		{
			list->next = (t_plist*)malloc(sizeof(t_plist));
			list->next->no = i;
			pipe(list->next->pipe);
			list->next->next = NULL;
			list = list->next;
			i++;
		}
		return (o);
	}
	return (NULL);
}
