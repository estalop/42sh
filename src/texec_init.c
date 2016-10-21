/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/10/20 14:06:18 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

static	t_exec	**addbuiltins(t_exec **tree)
{
	char	**builtins;
	int		i;

	if (!(builtins = (char**)malloc(sizeof(char*) * 6)))
		return (NULL);
	i = 0;
	while (i < 6)
		builtins[i++] = NULL;
	if (!(builtins[0] = ft_strdup("cd"))
		|| !(builtins[1] = ft_strdup("env"))
		|| !(builtins[2] = ft_strdup("setenv"))
		|| !(builtins[3] = ft_strdup("unsetenv"))
		|| !(builtins[4] = ft_strdup("history")))
	{
		ft_deltab(builtins);
		return (NULL);
	}
	i = 0;
	while (i < 5)
	{
		if (!(texec_check(builtins[i], *tree)) &&
		!(texec_add(builtins[i], tree)))
		{
			texec_del(tree);
			tree = NULL;
			free(builtins);
			return (NULL);
		}
		i++;
	}
	free(builtins);
	return (tree);
}

static t_exec	**dirtotexec(DIR *dir, t_exec **tree)
{
	struct dirent	*dirent;

	while ((dirent = readdir(dir)))
	{
		if (dirent->d_name[0] != '.')
		{
	//		if (ft_is_exec(dirent->d_type))
	//		{
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
	//		}
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
	res = &tree;
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
	return ((res = addbuiltins(res)) ? *res : NULL);
}
