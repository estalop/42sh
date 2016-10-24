/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfiles_getlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:20:53 by tbayet            #+#    #+#             */
/*   Updated: 2016/10/17 16:49:00 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

static t_files	*tfiles_new(char *str)
{
	t_files	*new;

	if (!(new = (t_files*)malloc(sizeof(t_files))))
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->name = str;
	return (new);
}

static t_files	*tfiles_add(t_files *new, t_files **lst)
{
	t_files	*tmp;

	if (!new)
		return (NULL);
	tmp = *lst;
	if (tmp)
	{
		if (ft_strcmp(new->name, tmp->name) < 0)
		{
			if (tmp->prev)
				tfiles_add(new, &(tmp->prev));
			else
				tmp->prev = new;
		}
		else
		{
			if (tmp->next)
				tfiles_add(new, &(tmp->next));
			else
				tmp->next = new;
		}
	}
	return (*lst);
}

static t_files	*tfiles_create(char *path, char *name)
{
	t_files			*lst;
	DIR				*dir;
	struct dirent	*dirent;
	int				len;

	lst = NULL;
	len = ft_strlen(name);
	if ((dir = opendir(path)))
	{
		while ((dirent = readdir(dir)))
		{
			if (ft_strncmp(name, dirent->d_name, len) == 0)
			{
				if (!(tfiles_add(tfiles_new(dirent->d_name), &lst)))
				{
					tfiles_del(&lst);
					closedir(dir);
					return (NULL);
				}
			}
		}
		closedir(dir);
	}
	return (lst);
}

char			**tfiles_getlst(char *pwd, char *str)
{
	int		i;
	t_files	*lst;
	char	*name;
	char	*path;
	char	**res;

	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != '/')
		i--;
	path = (str[i] == '/') ? ft_strndup(str, i + 1) : ft_strdup(pwd);
	if (!path)
		return (NULL);
	if (!(name = ft_strdup(str + i + 1)))
	{
		ft_strdel(&path);
		return (NULL);
	}
	if (!(lst = tfiles_create(path, name)))
	{
		ft_strdel(&path);
		ft_strdel(&name);
		return (NULL);
	}
	if (!(res = tfiles_totab(&lst)))
	{
		ft_strdel(&path);
		ft_strdel(&name);
		tfiles_del(&lst);
		return (NULL);
	}
	ft_strdel(&path);
	ft_strdel(&name);
	return (res);
}