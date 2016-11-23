/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/23 13:22:15 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

static	t_exec	**addbuiltins(t_exec **tree)
{
	if (!(texec_add("cd", tree))
		|| !(texec_add("env", tree))
		|| !(texec_add("setenv", tree))
		|| !(texec_add("unsetenv", tree))
		|| !(texec_add("history", tree))
		|| !(texec_add("echo", tree)))
	{
		texec_del(tree);
		tree = NULL;
		return (NULL);
	}
	return (tree);
}

static t_exec	**dirtotexec(DIR *dir, t_exec **tree)
{
	struct dirent	*dirent;

	while ((dirent = readdir(dir)))
	{
		if (dirent->d_name[0] != '.')
		{
			if (!(texec_check(dirent->d_name, *tree)))
			{
				if (!(texec_add(dirent->d_name, tree)))
				{
					closedir(dir);
					texec_del(tree);
					tree = NULL;
					return (NULL);
				}
			}
		}
	}
	closedir(dir);
	return (tree);
}

t_exec			*files_sort(char **files)
{
	t_exec	**res;
	t_exec	*tree;
	char	**ptr;
	DIR		*dir;

	if (!(tree = texec_new('\0', NULL)))
		return (NULL);
	if (!addbuiltins(res = &tree))
		return (NULL);
	ptr = files;
	while (*ptr)
	{
		if ((dir = opendir(*ptr)))
		{
			if (!(res = dirtotexec(dir, res)))
				return (NULL);
		}
		else
		{
			ft_putstr_fd("Error in PATH: can't open ", 2);
			ft_putendl_fd(*ptr, 2);
		}
		ptr++;
	}
	return (tree);
}
