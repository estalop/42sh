/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curpath_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 12:54:11 by jbobin            #+#    #+#             */
/*   Updated: 2017/01/08 19:15:44 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*ft_new_curpath(char *curpath, char *tmp, char *tmp2, int i)
{
	int	j;

	if (curpath[i + 1] == '.' && (curpath[i + 2] == '/' \
				|| curpath[i + 2] == '\0'))
	{
		j = i >= 2 ? i - 2 : 0;
		while (j > 0 && curpath[j] != '/')
			j--;
		if (curpath[j] == '/')
			tmp2 = ft_strsub(curpath, 0, j);
		if (tmp2)
			tmp = ft_strjoin(tmp2, &curpath[i + 2]);
	}
	else if (curpath[i + 1] == '/' || curpath[i + 1] == '\0')
	{
		tmp2 = ft_strsub(curpath, 0, i - 1);
		tmp = ft_strjoin(tmp2, &curpath[i + 1]);
	}
	ft_strdel(&tmp2);
	if (tmp)
		return (tmp);
	return (NULL);
}

static t_cdstruct	*ft_clean_curpath(t_cdstruct *new)
{
	int		i;
	char	*tmp;

	if ((i = -1) && (!new || !new->curpath))
	{
		ft_free_cdstruct(&new);
		return (NULL);
	}
	while (new->curpath[++i] != '\0' && !(tmp = NULL))
		if (new->curpath[i] == '.' &&
			(tmp = ft_new_curpath(new->curpath, NULL, NULL, i)))
		{
			i = -1;
			ft_strdel(&new->curpath);
			new->curpath = tmp;
		}
	if (ft_strlen(new->curpath) > 1 && \
		new->curpath[ft_strlen(new->curpath) - 1] == '/')
	{
		tmp = ft_strsub(new->curpath, 0, ft_strlen(new->curpath) - 1);
		ft_strdel(&new->curpath);
		new->curpath = tmp;
	}
	return (new);
}

static char			*ft_complete_curpath(char *argv, char **env, int opt)
{
	char	*curpath;
	int		i;
	char	buf[255];
	char	*tmp;

	i = 0;
	tmp = NULL;
	ft_bzero(&buf, 254);
	if (argv[0] != '/')
	{
		while (env[i] && ft_strncmp(env[i], "PWD=", 4))
			i++;
		if (opt == 1 || (env && env[i] && env[i][ft_strlen(env[i]) - 1] != '/')\
		|| (env && !env[i]))
			tmp = ft_strjoin((env[i] && opt != 1) ? &env[i][4] \
				: getcwd(buf, 255), "/");
		else if (env && env[i])
			tmp = ft_strdup(&env[i][4]);
		curpath = ft_strjoin(tmp, argv);
		ft_strdel(&tmp);
	}
	else
		curpath = ft_strdup(argv);
	return (curpath);
}

static t_cdstruct	*ft_set_curpath(char *argv, int opt, char **env, int *j)
{
	t_cdstruct	*new;

	if (!(new = (t_cdstruct*)malloc(sizeof(t_cdstruct))))
	{
		*j = -6;
		return (NULL);
	}
	new->argv = argv;
	new->opt = opt;
	if (new->argv[0] != '/' && ft_strncmp(new->argv, "./", 2) && \
		ft_strncmp(new->argv, "../", 3))
		new->argv = ft_cdpath(argv, env);
	new->curpath = ft_complete_curpath(argv, env, opt);
	if (opt == 1)
		return (new);
	return (ft_clean_curpath(new));
}

t_cdstruct			*ft_get_cdinfo(char *buf, char **env, int *j)
{
	char	**tmp;
	char	*new;
	int		opt;
	int		i;

	if ((tmp = ft_split(buf)) == NULL)
	{
		*j = -6;
		return (NULL);
	}
	i = 1;
	while (!(opt = 0) && tmp[i] && tmp[i][0] == '-')
	{
		if (tmp[i][1] == 'P')
			opt = 1;
		else if (tmp[i][1] == '\0' || tmp[i][1] == '/')
			break ;
		i++;
	}
	if (!(new = ft_opt_home(tmp[i], env, 0)))
		*j = ft_print_error_cd(tmp[i]);
	ft_free_tab(&tmp);
	if (new)
		return (ft_set_curpath(new, opt, env, j));
	return (NULL);
}
