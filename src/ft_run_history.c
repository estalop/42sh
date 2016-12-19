/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:00:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/12/19 15:25:57 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_run_history_beta2(char *home, t_prstruct *proc, int exit)
{
	char	*str;

	str = ft_strjoin(home, "/.42sh");
	ft_write_history_file2(proc->histo2, open(str, O_RDWR | O_TRUNC
	| O_CREAT, S_IRUSR | S_IWUSR), 1, exit);
	ft_strdel(&str);
	return (0);
}

static int	ft_run_history_beta(t_prstruct *proc)
{
	t_dlist		*histo2;

	ft_delete_list(proc->histo2);
	histo2 = NULL;
	histo2 = dlist_new(proc->histo2);
	proc->histo2 = histo2;
	return (0);
}

static int	ft_run_history_part2(char *arg, char *opt, t_prstruct *pro,
	int index)
{
	int	e;

	if (ft_strchr(opt, 'c'))
		e = ft_run_history_beta(pro);
	if (ft_strchr(opt, 'd'))
		e = ft_run_history3(arg, pro->histo2, index);
	if (ft_strchr(opt, 'a'))
		e = ft_run_history4(ft_get_home(pro->env[2]), pro->histo2);
	if (ft_strchr(arg, 'n'))
		ft_run_history5(arg, ft_get_home(pro->env[2]), pro->histo2, index);
	if (ft_strchr(arg, 'r'))
		e = ft_run_history5(arg, ft_get_home(pro->env[2]), pro->histo2, index);
	if (ft_strchr(arg, 's'))
		ft_add_data(pro->histo2, arg + index + 2, 0);
	if (ft_strchr(arg, 'p'))
		e = -7;
	ft_strdel(&opt);
	return (e);
}

static int	ft_parsing_history(char *arg, int index)
{
	while (index != -1 && arg[index] != '\0')
	{
		while (arg[index] == ' ' || arg[index] == '\t' \
			|| arg[index] == '\r' || arg[index] == '\n')
			index++;
		if (ft_isdigit(arg[index]))
			return (index);
		if (arg[index] == '-')
			return (index);
		if (arg[index] == '<' || arg[index] == '>')
		{
			while (arg[index] == '<' || arg[index] == '>' || arg[index] == ' ' \
			|| arg[index] == '\t' || arg[index] == '\r' || arg[index] == '\n')
				index++;
			while (arg[index] != '\0' && arg[index] != ' ' && \
			arg[index] != '\t' && arg[index] != '\r' && arg[index] != '\n')
				index++;
		}
		else if (arg[index] != '\0')
			return (-1);
		index++;
	}
	return (index);
}

int			ft_run_history(char *arg, char *home, t_prstruct *proc, int exit)
{
	int			index;
	char		*opt;

	if (home == NULL)
		return (-1);
	index = 0;
	if ((index = ft_parsing_history(arg, index)) == -1)
		return (-6);
	if (arg[index] >= '0' && arg[index] <= '9')
		return (-4);
	else if (arg[index] == '\0')
		return (-5);
	if (!(opt = ft_check_options_history(arg, 0, 0, NULL)))
	{
		ft_strdel(&opt);
		return (-8);
	}
	if (arg[index] == '-')
		index++;
	if (ft_strchr(arg, 'w'))
	{
		ft_strdel(&opt);
		return (ft_run_history_beta2(home, proc, exit));
	}
	return (ft_run_history_part2(arg, opt, proc, index));
}
