/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:52:02 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/30 15:10:05 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (proc->father && proc->father != proc->id)
	{
		proc->id = wait(&proc->stat_lock);
		ft_kill_process(&proc->list, proc->id);
	}
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
	char	**com;
	int		i;
	int		j;
	int		c;

	j = 0;
	com = NULL;
	i = 1;
	c = 0;
	if (!l)
		return (NULL);
	i += ft_strcnts(l, "&&");
	i += ft_strcnts(l, "||");
	i += ft_strcnt(l, ';');
	if (!(com = ft_memalloc((sizeof(char **) * i) + 1)))
		return (NULL);
	i = 0;
	while (l[i] && (l[i] == ' ' || l[i] == '\t'))
		i++;
	if (l[i] == '|' || l[i] == '&')
	{
		ft_printf("42sh: parse error near '%c'\n", l[i]);
		free(com);
		return (NULL);
	}
	while (l[i])
	{
		if ((!ft_strncmp(&l[i], "&&", 2) && ft_strncmp(&l[i], "&&&", 3)) || \
			(!ft_strncmp(&l[i], "||", 2) && ft_strncmp(&l[i], "|||", 3)) || \
			(!ft_strncmp(&l[i], ";", 1) && ft_strncmp(&l[i], ";;", 2)))
		{
			com[c] = ft_strsub(l, j, i - j);
			c++;
			j = i + 1;
			i += 2;
		}
		else if (!ft_strncmp(&l[i], "&&&", 3) || \
		!ft_strncmp(&l[i], "|||", 3) || !ft_strncmp(&l[i], ";;", 2))
		{
			ft_printf("42sh: parse error near '%c'\n", l[i]);
			t->err = -1;
			com[c + 1] = NULL;
			ft_free_tab(&com);
			return (NULL);
		}
		i++;
	}
	com[c] = ft_strsub(l, j, i - j);
	com[c + 1] = NULL;
	return (com);
}

void		ft_preprocess(char **tmp, t_prstruct *proc, char **path, \
						t_hered *heredoc)
{
	t_operators	t;

	ft_bzero(&t, sizeof(t_operators));
	t.com = ft_preprocesssplit(*tmp, &t);
	ft_strdel(tmp);
	if (t.err == -1)
	{
		ft_free_tab(&t.com);
		return ;
	}
	while (t.com != NULL && t.com[t.j] != NULL && !t.err)
	{
		if ((t.com[t.j][0] == '&' && proc->stat_lock == 0) || \
	(t.com[t.j][0] == '|' && proc->stat_lock != 0 && proc->stat_lock < 128) || \
			(t.com[t.j][0] != '&' && t.com[t.j][0] != '|'))
		{
			if ((t.com[t.j][0] == '&' && proc->stat_lock == 0) || \
		(t.com[t.j][0] == '|' && proc->stat_lock != 0 && proc->stat_lock < 128))
				ft_process(&t.com[t.j][1], proc, path, heredoc);
			else if (t.com[t.j][0] != '&' && t.com[t.j][0] != '|')
				ft_process(t.com[t.j], proc, path, heredoc);
		}
		++t.j;
	}
	ft_free_tab(&t.com);
}
