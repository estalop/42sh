/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:40:28 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/21 15:41:47 by jbobin           ###   ########.fr       */
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

void		ft_execute(char **path, char *buf, char **env)
{
	char	*bin;
	char	**argv;
	int		i;

	i = 0;
	argv = ft_split(buf);
	bin = NULL;
	if (argv[0][0] == '~' || argv[0][0] == '-')
		bin = ft_strjoin(ft_home(env, argv[0][0]), &argv[0][1]);
	else if (ft_strchr(argv[0], '/') != NULL)
		bin = ft_strdup(argv[0]);
	else
		while (path != NULL && path[i] != NULL && bin == NULL)
		{
			bin = ft_strjoin(path[i++], argv[0]);
			if (bin != NULL && access(bin, F_OK) == -1)
				ft_strdel(&bin);
		}
	if (access(bin, F_OK) == -1)
		ft_error_path(0, argv[0]);
	else if (access(bin, X_OK) == -1)
		ft_error_path(-1, argv[0]);
	ft_set_home_in_argv(argv, env);
	ft_fork_ex(bin, &argv, env);
	ft_strdel(&bin);
}

void		ft_close_pipe(t_plist *tmp, t_prstruct *proc)
{
	proc->pipe = proc->pipe->next;
	close(tmp->pipe[0]);
	close(tmp->pipe[1]);
	free(tmp);
}

int			ft_exe_builtin(int i, char *buf, t_prstruct *proc, char **path)
{
	int		e;

	e = 0;
	if (buf[i] != '\0' && ft_strncmp(buf, "exit", 4) == 0)
	{
		ft_reset_term(0);
		e = ft_exit(&buf[i], 0);
	}
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "cd", 2) == 0)
		e = ft_cd(&buf[i], proc->env[2], 0, NULL);
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "env", 3) == 0)
		e = ft_env(&buf[i], &proc->env[1], path, 1);
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "setenv", 6) == 0)
		e = ft_setenv(&buf[i], &proc->env[0], proc->env[0], &proc->env[2]);
	else if (buf[i] != '\0' && e == 0 && \
			ft_strncmp(&buf[i], "unsetenv", 8) == 0)
		e = ft_unsetenv(&buf[i], &proc->env[2], proc->env[2]);
	return (e);
}
