/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:53:34 by chdenis           #+#    #+#             */
/*   Updated: 2017/01/10 16:45:25 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_fork_ex(char *bin, char ***argv, char **env)
{
	char	**av;

	av = *argv;
	if (access(bin, X_OK) != -1)
		if (execve(bin, av, env) == -1)
			ft_error_path(1, av[0]);
	exit(1);
}

char		*ft_check_bin(char *buf, char **env, char **path, int i)
{
	char	*bin;
	char	**a;

	a = ft_split(buf);
	if (!(bin = NULL) && (!ft_strcmp(a[0], "env") || !ft_strcmp(a[0], "cd") || \
	!ft_strcmp(a[0], "setenv") || !ft_strcmp(a[0], "unsetenv") || \
	!ft_strcmp(a[0], "history") || !ft_strcmp(a[0], "echo") || \
	!ft_strcmp(a[0], "exit") || !ft_strcmp(a[0], "export") || \
	!ft_strcmp(a[0], "unset")))
	{
		bin = ft_strdup(a[0]);
		ft_free_tab(&a);
		return (bin);
	}
	if (a[0][0] == '~' || a[0][0] == '-')
		bin = ft_strjoin(ft_home(env, a[0][0]), &a[0][1]);
	else if (ft_strchr(a[0], '/') != NULL)
		bin = ft_strdup(a[0]);
	else
		while (path != NULL && path[i] != NULL && bin == NULL)
			if ((bin = ft_strjoin(path[i++], a[0])) && access(bin, F_OK) == -1)
				ft_strdel(&bin);
	return (ft_check_bin_anx(&bin, &a));
}

void		ft_execute(char *buf, char **env, int e, t_prstruct *proc)
{
	char	**argv;
	int		i;

	i = 0;
	ft_son_builtin(&buf, e, env, proc);
	argv = ft_split(buf);
	ft_set_home_in_argv(argv, env);
	ft_fork_ex(proc->bin, &argv, env);
}

void		ft_close_pipe(t_plist *tmp, t_prstruct *proc)
{
	proc->pipe = proc->pipe->next;
	close(tmp->pipe[0]);
	close(tmp->pipe[1]);
	free(tmp);
}

int			ft_exe_builtin(int i, char *buf, t_prstruct *proc)
{
	int		e;

	if ((e = -1) && buf[i] == '\0')
		return (e);
	if (ft_strncmp(buf, "exit", 4) == 0)
	{
		ft_reset_term(0);
		texec_del(&proc->exec);
		e = ft_exit(&buf[i], 0, proc);
	}
	else if (ft_strncmp(&buf[i], "cd", 2) == 0)
		e = ft_cd(&buf[i], &proc->env[2], 1, NULL);
	else if (ft_strncmp(&buf[i], "env", 3) == 0)
		e = ft_env(&buf[i], &proc->env[1], 1);
	else if (ft_strncmp(&buf[i], "setenv", 6) == 0)
		e = ft_setenv(&buf[i], &proc->env[0], proc->env[0], &proc->env[2]);
	else if (ft_strncmp(&buf[i], "unsetenv", 8) == 0)
		e = ft_unsetenv(&buf[i], &proc->env[2], proc->env[2]);
	else if (ft_strncmp(&buf[i], "history", 7) == 0)
		e = ft_run_history(&buf[i] + 7, ft_get_home(proc->env[2]), proc, 0);
	else if (ft_strncmp(&buf[i], "export", 6) == 0)
		e = ft_export(&buf[i], 0);
	else if (ft_strncmp(&buf[i], "unset", 5) == 0)
		e = ft_unset(&buf[i]);
	return (e);
}
