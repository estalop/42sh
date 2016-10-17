/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:07:37 by jbobin            #+#    #+#             */
/*   Updated: 2016/10/17 10:29:01 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_print_cd(char *argv, char *buf)
{
	ft_putendl(buf);
    if (access(buf, F_OK) == 0)
		if (access(buf, X_OK) == 0)
			if (chdir(buf) == -1)
			{
				ft_putstr_fd("cd: not a directory: ", 2);
				ft_putendl_fd(argv, 2);
			}
			else
				return (0);
		else
		{
			ft_putstr_fd("cd: permission denied: ", 2);
			ft_putendl_fd(argv, 2);
		}
	else
	{
		ft_putstr_fd("cd: no such file or directory: " , 2);
		ft_putendl_fd(argv, 2);
	}
	return (-1);
}

static t_cdstruct	*ft_clean_curpath(t_cdstruct *new)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (new->curpath[i] != '\0')
	{
		tmp = NULL;
		tmp2 = NULL;
		if (new->curpath[i] == '.')
		{
			if (new->curpath[i + 1] == '.' && new->curpath[i + 2] == '/')
			{
				j = i;
				while (j > 0 && new->curpath[j] != '/')
					j--;
				if (j > 0 && new->curpath[j] == '/')
					tmp2 = ft_strsub(new->curpath, 0, j);
				if (tmp2)
					tmp = ft_strjoin(tmp2, &new->curpath[i + 3]);
			}
			else if (new->curpath[i + 1] == '/')
			{
				tmp2 = ft_strsub(new->curpath, 0, i);
				tmp = ft_strjoin(tmp2, &new->curpath[i + 2]);
			}
			ft_strdel(&tmp2);
			if (tmp)
			{
				ft_strdel(&new->curpath);
				new->curpath = tmp;
				i = -1;
			}
		}
		i++;
	}
	return (new);
}

static t_cdstruct	*ft_set_curpath(char *argv, int opt, char **env)
{
	t_cdstruct	*new;
	char		buf[255];
	int			i;

	i = 0;
	if (!(new = (t_cdstruct*)malloc(sizeof(t_cdstruct))))
		return (NULL);
	new->argv = argv;
	new->opt = opt;
	if (new->argv[0] != '/' && ft_strncmp(new->argv, "./", 2) && \
		ft_strncmp(new->argv, "../", 3))
		new->argv = ft_cdpath(argv, env);
	if (new->argv[0] != '/')
	{
		while (env[i] && ft_strncmp(env[i], "PWD=", 4))
			i++;
		new->curpath = (env[i] && opt != 1) ? ft_strjoin(&env[i][4], new->argv)\
		 : ft_strjoin(getcwd(buf, 255), new->argv);
	}
	else
		new->curpath = ft_strdup(new->argv);
	if (opt == 1)
		return (new);
	return (ft_clean_curpath(new));
}

t_cdstruct			*ft_get_cdinfo(char *buf, char **env)
{
	char	**tmp;
	char	*new;
	int		opt;
	int		i;

	if ((tmp = ft_split(buf)) == NULL)
		return (NULL);
	i = 1;
	opt = 0;
	while (tmp[i] && tmp[i][0] == '-')
	{
		if (tmp[i][1] == 'P')
			opt = 1;
		else if (tmp[i][1] == '\0' || tmp[i][1] == '/')
			break ;
		i++;
	}
	new = ft_opt_home(tmp[i], env, 0);
	ft_free_tab(&tmp);
	return (ft_set_curpath(new, opt, env));
}
