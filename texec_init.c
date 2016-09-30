/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/29 14:11:40 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

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
	return (*res);
}
