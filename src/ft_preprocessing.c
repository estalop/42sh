/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprossessing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:52:02 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/28 13:22:21 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipe(t_prstruct *proc, char **buf, char **path)
{
	int	e;

	while (proc->i <= proc->npipe)
	{
		proc->s = 0;
		while (buf[proc->i][proc->s] == '\t' || buf[proc->i][proc->s] == ' ')
			proc->s++;
		e = ft_exe_builtin(proc->s, buf[proc->i], proc);
		if ((proc->bin = ft_check_bin(buf[proc->i], proc->env[2], path, 0)))
		{
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
	process->stat_lock = ft_returnofprocess(process->stat_lock);
	signal(2, &ft_signal_stop);
}

void		ft_preprocess(char **tmp, t_prstruct *proc, char **path, \
						t_hered *heredoc)
{
	char	**com;
	int		j;

	com = ft_strsplit(*tmp, ';');
	ft_strdel(tmp);
	j = 0;
	while (com != NULL && com[j] != NULL)
		ft_process(com[j++], proc, path, heredoc);
	ft_free_tab(&com);
}
