/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:53:47 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/26 09:18:38 by tbayet           ###   ########.fr       */
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

t_exec	*create_tree(t_env *env)
{
	char	**files;
	char	**tab;
	char	*str;
	t_exec	*tree;

	str = "l";
	if (!(files = get_pathes(env)))
		return (NULL);
	tree = files_sort(files);
	tab = complete_me(str, tree);
	ft_deltab(files);
	texec_del(&tree);
	return (tree);
}
