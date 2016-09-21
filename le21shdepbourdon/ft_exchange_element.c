/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:37:39 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:53:02 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_exchange_element2(t_dlist *line, char *oldpwd)
{
	int		pos;
	char	*test2;

	pos = ft_search_list(line, "OLDPWD=");
	line = ft_del_ele_list(line, pos, line->p_head, 1);
	test2 = ft_strjoin("OLDPWD=", oldpwd + 4);
	if (pos == 0)
		line = ft_add_data(line, test2);
	else
		line = ins_avant(line, test2, line->p_head, pos);
	free(test2);
	free(oldpwd);
	return (line);
}

t_dlist		*ft_exchange_element(t_dlist *line, char *test1,
	char *test4)
{
	int		pos;
	char	*oldpwd;
	char	*new_pwd;

	pos = ft_search_list(line, "PWD=");
	if (pos != 0 && ft_strlen(ft_get_ele(line, pos)) > 4)
		oldpwd = ft_strdup(ft_get_ele(line, pos));
	else
	{
		test4 = getcwd(0, 0);
		oldpwd = ft_strjoin("PWD=", test4);
		free(test4);
	}
	line = ft_del_ele_list(line, pos, line->p_head, 1);
	new_pwd = getcwd(0, 0);
	test1 = ft_strjoin("PWD=", new_pwd);
	if (pos == 0)
		line = ft_add_data(line, test1);
	else
		line = ins_avant(line, test1, line->p_head, pos);
	free(test1);
	free(new_pwd);
	return (ft_exchange_element2(line, oldpwd));
}
