/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:08:18 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/21 11:10:38 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_get_path(char **environ)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	path = NULL;
	while (environ != NULL && environ[i] != NULL)
	{
		if (ft_strncmp("PATH=", environ[i], 5) == 0)
			path = ft_strsplit(&environ[i][5], ':');
		i++;
	}
	i = 0;
	while (environ != NULL && path != NULL && path[i] != NULL)
	{
		if (path[i][0] != '\0' && path[i][ft_strlen(path[i]) - 1] != '/')
		{
			tmp = ft_strjoin(path[i], "/");
			ft_strdel(&path[i]);
			path[i] = tmp;
		}
		i++;
	}
	return (path);
}

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
	char		**tmp;

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

static void	ft_loop(t_termcaps *cap, t_prstruct *proc)
{
	char	**path;
	char	**com;
	char	*tmp;
	int		j;

	ft_init_histo(proc, cap);
	while (42 && !(j = 0))
	{
		path = ft_get_path(proc->env[0]);
		proc->env[1] = ft_tabdup(proc->env[2]);
		if (ft_read_termcap(cap) == 1)
			break ;
		ft_reset_term(0);
		tmp = cap->cmd ? cap->cmd : cap->str;
		if (tmp != NULL)
		{
			tmp = ft_replace_excla(tmp, proc, 0, 0);
			if (ft_strlen(tmp) > 0 && ft_check_tmp(tmp) == 1)
				ft_add_data(proc->histo2, tmp, 0);
		}
		com = ft_strsplit(tmp, ';');
		ft_strdel(&tmp);
		j = 0;
		while (com != NULL && com[j] != NULL)
		{
			ft_process(com[j], proc, path, cap->heredoc);
			j++;
		}
		ft_main_free(&proc->env[1], cap, &path, &com);
		if (proc->env[0] != NULL &&
			proc->env[1] != NULL && proc->env[2] != NULL)
			ft_sync_env(proc->env, 0, 0, 0);
		cap->histo2 = proc->histo2;
	}
	ft_free_tab(&path);
	ft_free_tab(&proc->env[1]);
}

int			main(void)
{
	t_termcaps		*cap;
	t_prstruct		process;

	cap = ft_struct_innit(0);
	ft_bzero(&process, sizeof(t_prstruct));
	process.herepipe = -1;
	signal(2, &ft_signal_stop);
	signal(18, SIG_IGN);
	signal(28, &ft_signal_size);
	process.env[0] = ft_create_environ(0);
	process.env[2] = ft_tabdup(process.env[0]);
	cap->bin = create_tree(process.env[0]);
	process.exec = cap->bin;
	ft_init_termcap(cap);
	ft_loop(cap, &process);
	ft_run_history(" -w", ft_get_home(process.env[2]), &process, 1);
	ft_free_tab(&process.env[2]);
	ft_free_tab(&process.env[0]);
	texec_del(&cap->bin);
	return (0);
}
