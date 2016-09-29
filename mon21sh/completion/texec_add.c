/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texec_add.                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:22:01 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/29 15:08:14 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocompletion.h"
#include "fucknorm.h"

static t_exec	*texec_runover(t_exec *tmp_tree, char *ptr, t_exec **parent)
{
	while (tmp_tree && tmp_tree->change && (*ptr >= tmp_tree->change->c))
	{
		*parent = tmp_tree;
		tmp_tree = tmp_tree->change;
	}
	return (tmp_tree);
}

static t_exec	*texec_ifn(t_exec *tmp_tree, char *file, char *ptr)
{
	char	*value;
	t_exec	*new;

	value = (ptr[1] == '\0') ? file : NULL;
	if (!(new = texec_new(*ptr, value)))
		return (NULL);
	tmp_tree->next = new;
	tmp_tree = tmp_tree->next;
	return (tmp_tree);
}

t_exec			*texec_ifs(t_exec **tree, t_exec **parent, t_exec *tmp_tree,
							t_fnorm fnorm)
{
	t_exec	*new;
	char	*ptr;

	ptr = fnorm.s2;
	if (!(new = texec_new(*ptr, fnorm.s1)))
		return (texec_del(tree));
	if (!(tmp_tree))
		(*tree)->next = new;
	else if (*ptr < tmp_tree->c)
	{
		new->change = tmp_tree;
		if (*parent)
			(*parent)->next = new;
	}
	else if (*ptr > tmp_tree->c)
	{
		if (tmp_tree->change)
			new->change = tmp_tree->change;
		tmp_tree->change = new;
	}
	tmp_tree = new;
	return (tmp_tree);
}

static t_exec	*texec_ifr(t_exec *tmp_tree, t_exec **tree, t_exec **parent,
						t_fnorm fnorm)
{
	char	*value;
	char	*ptr;
	char	*file;

	value = fnorm.s1;
	ptr = fnorm.s2;
	file = fnorm.s3;
	if (tmp_tree && *ptr == tmp_tree->c)
	{
		if ((value)
		&& (!(tmp_tree->name) && !(tmp_tree->name = ft_strdup(file))))
			return (texec_del(tree));
	}
	else if (!(tmp_tree = texec_ifs(tree, parent, tmp_tree, fnorm)))
		return (NULL);
	return (tmp_tree);
}

t_exec			**texec_add(char *file, t_exec **tree)
{
	char	*value;
	t_exec	*tmp_tree;
	t_exec	*parent;
	char	*ptr;

	ptr = file;
	((*tree)->nbelems)++;
	tmp_tree = (*tree)->next;
	parent = *tree;
	while (*ptr)
	{
		value = (ptr[1] == '\0') ? file : NULL;
		tmp_tree = texec_runover(tmp_tree, ptr, &parent);
		if (!(tmp_tree = texec_ifr(tmp_tree, tree, &parent,
				ft_fucknorme(value, ptr, file))))
			return (NULL);
		(tmp_tree->nbelems)++;
		ptr++;
		parent = tmp_tree;
		if (tmp_tree->next || !(*ptr))
			tmp_tree = tmp_tree->next;
		else if (!(tmp_tree = texec_ifn(tmp_tree, file, ptr)))
			return (NULL); // (texec_del(tree));
	}
	return (tree);
}
