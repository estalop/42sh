/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:52:50 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/05 13:25:41 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prstruct	*g_process;

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

static char	*ft_loopanx(char *tmp, t_prstruct *proc)
{
	if (tmp != NULL)
	{
		tmp = ft_replace_excla(tmp, proc, 0, 0);
		if (ft_strlen(tmp) > 0 && ft_check_tmp(tmp) == 1)
			ft_add_data(proc->histo2, tmp, 0);
	}
	return (tmp);
}

static void	ft_loop(t_termcaps *cap, t_prstruct *proc)
{
	char	**path;
	char	*tmp;

	ft_init_histo(proc, cap);
	while (42)
	{
		cap->str = NULL;
		cap->cmd = NULL;
		path = ft_get_path(proc->env[0]);
		proc->path = path;
		proc->env[1] = ft_tabdup(proc->env[2]);
		if (ft_read_termcap(cap) == 1)
			break ;
		ft_reset_term(0);
		tmp = cap->cmd ? cap->cmd : cap->str;
		tmp = ft_loopanx(tmp, proc);
		ft_preprocess(&tmp, proc, path, cap->heredoc);
		ft_main_free(&proc->env[1], cap, &path);
		if (proc->env[0] != NULL && proc->env[1] && proc->env[2])
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

	g_process = &process;
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
	free_local_var();
	texec_del(&cap->bin);
	return (0);
}
