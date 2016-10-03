/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 10:40:28 by jbobin            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/10/03 09:29:18 by jbobin           ###   ########.fr       */
=======
/*   Updated: 2016/10/01 16:45:22 by pbourdon         ###   ########.fr       */
>>>>>>> b48aa67925436169ec6848114bdcf1a79eff97de
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
	ft_exit("exit 1", 0);
}

char		*ft_check_bin(char *buf, char **env, char **path, int i)
{
	char	*bin;
	char	**argv;

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
	if (access(bin, F_OK) == -1 || access(bin, X_OK) == -1)
		ft_strdel(&bin);
	ft_free_tab(&argv);
	return (bin);
}

void		ft_execute(char *buf, char **env, char *bin)
{
	char	**argv;
	int		i;

	i = 0;
	argv = ft_split(buf);
	ft_set_home_in_argv(argv, env);
	ft_fork_ex(bin, &argv, env);
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

	e = 0;
	if (buf[i] != '\0' && ft_strncmp(buf, "exit", 4) == 0)
	{
		ft_reset_term(0);
		texec_del(&proc->exec);
		e = ft_exit(&buf[i], 0);
	}
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "cd", 2) == 0)
		e = ft_cd(&buf[i], proc->env[2], 0, NULL);
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "env", 3) == 0)
		e = ft_env(&buf[i], &proc->env[1], 1);
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "setenv", 6) == 0)
		e = ft_setenv(&buf[i], &proc->env[0], proc->env[0], &proc->env[2]);
	else if (buf[i] != '\0' && e == 0 && \
			ft_strncmp(&buf[i], "unsetenv", 8) == 0)
		e = ft_unsetenv(&buf[i], &proc->env[2], proc->env[2]);
	else if (buf[i] != '\0' && e == 0 && ft_strncmp(&buf[i], "history", 7) == 0)
		e = ft_run_history(&buf[i] + 7, ft_get_home(proc->env[2]), proc);
	return (e);
}
