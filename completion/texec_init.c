/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/26 09:15:58 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

static t_exec	*dirtotexec(DIR *dir, t_exec **tree)
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
					if (!(*tree = texec_add(dirent->d_name, tree)))
						return (texec_del(tree));
				}
	//		}
		}
	}
	closedir(dir);
	return (*tree);
}

t_exec			*files_sort(char **files)
{
	t_exec	*tree;
	char	**ptr;
	DIR		*dir;

	tree = NULL;
	ptr = files;
	while (*ptr)
	{
		if ((dir = opendir(*ptr)))
		{
			if (!(tree = dirtotexec(dir, &tree)))
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
