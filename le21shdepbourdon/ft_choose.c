/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 17:45:28 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 17:41:10 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*ft_search_file(char *arg)
{
	return (arg);
}

char		*ft_get_file(char *arg)
{
	char		*tmp;
	int			index;
	int			index2;

	index = 1;
	index2 = 0;
	tmp = malloc(sizeof(char) * ft_strlen(arg) + 1);
	while (arg[index] != '\0' && arg[index] != ' ' && arg[index] != '\t')
	{
		tmp[index2] = arg[index];
		index++;
		index2++;
	}
	tmp[index2] = '\0';
	return (ft_search_file(tmp));
}

char		**ft_init_tab(char *arg)
{
	char		**tab2;
	int			index;
	int			index2;

	tab2 = malloc(sizeof(char *) * ft_strlen(arg));
	index2 = 0;
	index = ft_strlen(ft_get_file(arg));
	while (arg[index] != '\0')
	{
		tab2[index2][0] = arg[index];
		tab2[index2][1] = '\0';
		index++;
		index2++;
	}
	return (tab2);
}

t_dlist		*ft_choose(char *arg, t_dlist *list)
{
	int			index;

	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' ||
			arg[index] == '\n' || arg[index] == '\r')
		index++;
	if (ft_strncmp("cd", arg, 2) == 0)
		ft_run_cd(arg, list, NULL, NULL);
	else if (ft_strncmp("echo", arg, 4) == 0)
		ft_run_echo(arg, list);
	else if (ft_strncmp("setenv", arg, 6) == 0)
		ft_run_setenv(arg, list);
	else if (ft_strncmp("env", arg, 3) == 0)
		ft_display_list(list);
	else if (ft_strncmp("unsetenv", arg, 8) == 0)
		ft_run_unsetenv(arg + 8, list);
	else if (ft_strncmp("exit", arg, 4) == 0 && ft_strlen(arg) == 4)
	{
		ft_delete_list(&list);
		return (list);
	}
	else if (ft_check_arg(arg + index, list, 0, ft_boucle(arg)) == 0)
		ft_error(arg, 3);
	return (list);
}
