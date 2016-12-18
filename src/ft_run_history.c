/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:00:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/12/18 14:06:10 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_run_history_beta2(char *home, t_prstruct *proc, int exit)
{
	char	*str;

	str = ft_strjoin(home, "/.42sh");
	ft_write_history_file2(proc->histo2, open(str, O_RDWR | O_TRUNC
	| O_CREAT, S_IRUSR | S_IWUSR), 1, exit);
	ft_strdel(&str);
	return (0);
}

int			ft_run_history_beta(t_prstruct *proc)
{
	t_dlist		*histo2;

	ft_delete_list(proc->histo2);
	histo2 = NULL;
	histo2 = dlist_new(proc->histo2);
	proc->histo2 = histo2;
	return (0);
}

int			ft_run_history_part2(char *arg, char *home, t_prstruct *proc,
	int index)
{
	if (ft_check_options_history(arg, 'c', index) == 1)
		return (ft_run_history_beta(proc));
	if (ft_check_options_history(arg, 'd', index) == 1)
		return (ft_run_history3(arg, proc->histo2, index));
	if (ft_check_options_history(arg, 'a', index) == 1)
		return (ft_run_history4(home, proc->histo2));
	if (ft_check_options_history(arg, 'n', index) == 1)
		return (ft_run_history5(arg, home, proc->histo2, index));
	if (ft_check_options_history(arg, 'r', index) == 1)
		return (ft_run_history5(arg, home, proc->histo2, index));
	if (ft_check_options_history(arg, 's', index) == 1)
		ft_add_data(proc->histo2, arg + index + 2, 0);
	return (0);
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

	if (home == NULL)
		return (-1);
	index = 0;
	if ((index = ft_parsing_history(arg, index)) == -1)
		return (-6);
	if (arg[index] >= '0' && arg[index] <= '9')
		return (-4);
	else if (arg[index] == '\0')
		return (-5);
	if (arg[index] == '-')
		index++;
	if (ft_check_options_history(arg, 'w', index) == 1)
		return (ft_run_history_beta2(home, proc, exit));
	return (ft_run_history_part2(arg, home, proc, index));
}
