/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_history2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 20:22:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/12/17 17:53:56 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_run_history2(char *arg, t_dlist *histo, int index)
{
	int		number;

	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' || \
		arg[index] == '\n')
		index++;
	number = ft_atoi(arg + index);
	ft_display_list4(histo, number);
	return (0);
}

int		ft_run_history3(char *arg, t_dlist *histo, int index)
{
	int		number;

	index++;
	number = ft_atoi(arg + index);
	if (number >= 0 && number <= histo->length)
		ft_del_ele_list(histo, number, histo->p_head, 0);
	else
		return (-2);
	return (0);
}

int		ft_run_history4(char *home, t_dlist *histo)
{
	char	*str;

	str = ft_strjoin(home, "./42sh");
	ft_write_history_file(histo, 0, open(str, O_RDWR | O_CREAT | O_APPEND,
	S_IRUSR | S_IWUSR), 1);
	ft_strdel(&str);
	return (0);
}

int		ft_run_history5(char *arg, char *home, t_dlist *histo, int index)
{
	char	*str;

	str = ft_strjoin(home, "/.42sh");
	ft_get_check_file(histo, open(str, O_RDONLY), 0, 0);
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
			arg[index] == '\n')
		index++;
	if (arg[index] == '-')
		index++;
	ft_strdel(&str);
	return (0);
}
