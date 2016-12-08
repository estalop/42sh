/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:34:56 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/08 16:52:19 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_termcaps	*ft_struct_innit(int mode)
{
	static t_termcaps	cap;
	int					i;

	if (!(i = 0) && mode == 0)
	{
		cap.exec = 0;
		cap.str = NULL;
		cap.cmd = NULL;
		cap.stop = NULL;
		cap.x = 0;
		cap.y = 0;
		cap.prompt = 0;
		cap.height = 0;
		cap.whidth = 0;
		cap.auto_wrap = 0;
		cap.auto_scroll = 0;
		cap.mi = 0;
		while (i < 500)
			cap.hist[i++] = NULL;
		cap.prom = NULL;
		cap.oldlen = 0;
		cap.i = 0;
		cap.neg = 0;
	}
	return (&cap);
}

void		ft_signal_stop(int sig)
{
	t_termcaps	*cap;
	int			i;

	if (sig == 2)
	{
		i = 0;
		cap = ft_struct_innit(1);
		ft_strdel(&cap->str);
		ft_strdel(&cap->stop);
		ft_strdel(&cap->cmd);
		ft_putchar('\n');
		while (i < cap->height)
		{
			tputs(cap->dc, 0, ft_output);
			i++;
		}
		cap->i = 0;
		cap->prom = ft_prompt(0);
		cap->neg = ft_strlen(cap->prom);
		cap->oldlen = 0;
		cap->prompt = ft_start_of_str(cap->str, cap);
		cap->x = cap->prompt;
		ft_putstr(cap->prom);
	}
}

static void	ft_signal_size_anx(t_termcaps *cap, char **tmp)
{
	if ((cap->height = tgetnum("li")) == 0 \
		|| (cap->whidth = tgetnum("co")) == 0 \
		|| !(cap->im = tgetstr("im", NULL)) \
		|| !(cap->bl = tgetstr("bl", NULL)) \
		|| !(cap->sf = tgetstr("sf", NULL)) \
		|| !(cap->sr = tgetstr("sr", NULL)) \
		|| !(cap->cr = tgetstr("cr", NULL)) \
		|| !(cap->cv = tgetstr("ch", NULL)) \
		|| !(cap->dc = tgetstr("dl", NULL)) \
		|| !(cap->cd = tgetstr("cd", NULL)) \
		|| !(cap->mr = tgetstr("mr", NULL)) \
		|| !(cap->me = tgetstr("me", NULL)) \
		|| !(cap->cl = tgetstr("cl", NULL)))
		ft_reset(cap, *tmp);
}

void		ft_signal_size(int sig)
{
	t_termcaps	*cap;
	char		*tmp;
	int			whidth;

	if (sig == 28)
	{
		cap = ft_struct_innit(1);
		tmp = cap->cmd ? cap->cmd : cap->str;
		whidth = cap->whidth;
		if (tgetent(cap->buf, "xterm-256color") < 0)
			tgetent(cap->buf, getenv("TERM"));
		ft_signal_size_anx(cap, &tmp);
		ft_putstr(cap->prom);
		if (tmp)
			ft_newputstr(&tmp[cap->prompt - cap->neg], cap);
	}
}

void		ft_signal_fork(int sig)
{
	t_termcaps	*cap;
	int			i;

	if (sig == 2)
	{
		i = 0;
		cap = ft_struct_innit(1);
		ft_putchar('\n');
		while (i < cap->height)
		{
			tputs(cap->dc, 0, ft_output);
			i++;
		}
		cap->prom = ft_prompt(0);
		cap->neg = ft_strlen(cap->prom);
		cap->prompt = ft_start_of_str(cap->str, cap);
		cap->x = cap->prompt;
		cap->i = 0;
		cap->oldlen = 0;
		ft_putstr(cap->prom);
		exit(0);
	}
}
