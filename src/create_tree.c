/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/11/23 11:25:10 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

char	**get_pathes(t_env *env)
{
	t_env	*tmp;
	char	**pathes;

	tmp = env;
	while (ft_strcmp(tmp->name, "PATH") != 0)
		tmp = tmp->next;
	if (!(pathes = ft_strsplit(tmp->value, ':')))
		return (NULL);
	return (pathes);
}

t_exec	*create_tree(char **env)
{
	char	**files;
	t_exec	*tree;

	if (!(files = ft_get_path(env)))
		return (NULL);
	tree = files_sort(files);
	ft_free_tab(&files);
	return (tree);
}
