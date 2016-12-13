/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:53:08 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/13 12:49:07 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipeanx(t_prstruct *proc)
{
	while (proc->father && proc->father != proc->id)
	{
		proc->id = wait(&proc->stat_lock);
		ft_kill_process(&proc->list, proc->id);
	}
}

static void	ft_pipe(t_prstruct *proc, char **buf, char **path)
{
	int	e;

	while (proc->i <= proc->npipe)
	{
		proc->err = 1;
		proc->s = 0;
		while (buf[proc->i][proc->s] == '\t' || buf[proc->i][proc->s] == ' ')
			proc->s++;
		e = ft_exe_builtin(proc->s, buf[proc->i], proc);
		if ((proc->bin = ft_check_bin(buf[proc->i], proc->env[2], path, 0)))
		{
			proc->err = 0;
			proc->father = ft_fork(&proc->list);
			if (proc->father == 0)
				ft_son(proc, buf, proc->env, e);
			else if (proc->i > 0)
				ft_close_pipe(proc->pipe, proc);
		}
		else if (proc->i > 0)
			ft_close_pipe(proc->pipe, proc);
		ft_strdel(&proc->bin);
		proc->i++;
	}
	ft_pipeanx(proc);
}

static void	ft_process(char *buf, t_prstruct *process, char **path, \
						t_hered *heredoc)
{
	char	**tmp;

	process->i = 0;
	while (buf[process->i] == ' ' || buf[process->i] == '\t')
		process->i++;
	if (buf[process->i] == '\0')
		return ;
	signal(2, &ft_sig_stop_ex);
	process->list = NULL;
	process->i = 0;
	process->heredoc = heredoc;
	if ((process->npipe = ft_count_pipe(buf)) == -1)
	{
		ft_putendl_fd("42sh: parse error", 2);
		signal(2, &ft_signal_stop);
		return ;
	}
	process->pipe = ft_create_pipe(process->npipe);
	tmp = ft_strsplit(buf, '|');
	ft_pipe(process, tmp, path);
	ft_free_tab(&tmp);
	ft_free_list(&process->list);
	process->stat_lock = process->err ? 1 : \
		ft_returnofprocess(process->stat_lock);
	signal(2, &ft_signal_stop);
}

static char	**ft_preprocesssplit(char *l, t_operators *t)
{
	t_preprocesssplit	p;

	p.j = 0;
	p.com = NULL;
	p.i = 1;
	p.c = 0;
	if (!l)
		return (NULL);
	p.i += ft_strcnts(l, "&&");
	p.i += ft_strcnts(l, "||");
	p.i += ft_strcnt(l, ';');
	if (!(p.com = ft_memalloc((sizeof(char **) * (p.i + 1)))))
		return (NULL);
	p.i = 0;
	while (l[p.i] && (l[p.i] == ' ' || l[p.i] == '\t'))
		p.i++;
	if (l[p.i] == '|' || l[p.i] == '&')
	{
		ft_printf("42sh: parse error near '%c'\n", l[p.i]);
		free(p.com);
		return (NULL);
	}
	if (ft_preprocesssplit_anx(l, t, &p))
		return (NULL);
	return (p.com);
}

void		ft_preprocess(char **tmp, t_prstruct *proc, char **path, \
						t_hered *heredoc)
{
	t_operators	t;

	ft_bzero(&t, sizeof(t_operators));
	t.com = ft_preprocesssplit(*tmp, &t);
	ft_strdel(tmp);
	if (t.err == -1)
		ft_free_tab(&t.com);
	if (t.err == -1)
		return ;
	while (t.com != NULL && t.com[t.j] != NULL && !t.err)
	{
		t.com[t.j] = parse_process(t.com[t.j]);
		if ((t.com[t.j][0] == '&' && proc->stat_lock == 0) || \
	(t.com[t.j][0] == '|' && proc->stat_lock != 0 && proc->stat_lock < 128) || \
			(t.com[t.j][0] != '&' && t.com[t.j][0] != '|'))
		{
			if ((t.com[t.j][0] == '&' && proc->stat_lock == 0) || \
		(t.com[t.j][0] == '|' && proc->stat_lock != 0 && proc->stat_lock < 128))
				ft_process(t.com[t.j] + 1, proc, path, heredoc);
			else if (t.com[t.j][0] != '&' && t.com[t.j][0] != '|')
				ft_process(t.com[t.j], proc, path, heredoc);
		}
		++t.j;
	}
	ft_free_tab(&t.com);
}
