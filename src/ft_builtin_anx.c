/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_anx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:32:41 by tviviand          #+#    #+#             */
/*   Updated: 2017/01/10 16:34:23 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_setenv_anx(char ***adenv, char ***nenv, t_structenv *t, char **env)
{
	if (t->argv[1] && (!ft_isalpha(t->argv[1][0]) ||
	!ft_strisalphadigit(t->argv[1])))
	{
		ft_printf("setenv: '%s': not a valid identifier\n", t->argv[1]);
		ft_free_tab(&t->argv);
		return (1);
	}
	*adenv = ft_subsetenv(*t, env);
	*nenv = ft_subsetenv(*t, *nenv);
	return (0);
}

void	ft_unsetenv_anx(int i, char ***adenv, t_structenv *t, char **env)
{
	while (t->argv[i] != NULL)
	{
		if (t->tmp2 == NULL)
			t->tmp2 = ft_strjoin(t->argv[i], "=");
		while (env[t->k])
		{
			if (ft_strncmp(t->tmp2, env[t->k], ft_strlen(t->tmp2)) == 0)
			{
				*adenv = ft_subunsetenv(*t, &env);
				t->k = -1;
			}
			++t->k;
		}
		ft_strdel(&t->tmp2);
		++i;
	}
}

void	ft_exit_anx(int *i, char ***argv, t_prstruct *proc)
{
	while (ft_isdigit((*argv)[1][*i]) == 1)
		*i = *i + 1;
	if ((int *)i == 0)
	{
		ft_run_history(" -w", ft_get_home(proc->env[2]), proc, 1);
		exit(0);
	}
	if (argv[1][*i] == '\0')
	{
		ft_run_history(" -w", ft_get_home(proc->env[2]), proc, 1);
		exit(ft_atoi((*argv)[1]));
	}
	else
		ft_putendl_fd("exit: invalid argument", 2);
}
