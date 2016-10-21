/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/10/20 13:29:29 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"

/*
** DEBUG (to delete)
*/

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

/*
** DEBUG (to delete)
*/

void	printexec(t_exec *exec)
{
	if (exec)
	{
		printf("%c[%s/%d] \n", exec->c, exec->name, exec->nbelems);
		write(1, "- ", 2);
		printexec(exec->next);
		printf(".\n");
		printexec(exec->change);
	}
}

/*
** Cree un arbre binaire contenant tous les executables
*/

t_exec	*create_tree(char **env)
{
	char	**files;
	t_exec	*tree;

	if (!(files = ft_get_path(env)))
		return (NULL);
	tree = files_sort(files);
	ft_free_tab(&files);
//	texec_del(&tree);
	return (tree);
}
