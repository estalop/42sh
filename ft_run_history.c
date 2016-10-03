/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:00:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/01 20:56:35 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_run_history_beta(t_prstruct *proc)
{
	t_dlist		*histo2;

	ft_delete_list(proc->histo2);
	histo2 = NULL;
	histo2 = dlist_new(proc->histo2);
	proc->histo2 = histo2;
	return (1);
}

int			ft_run_history_part2(char *arg, char *home, t_prstruct *proc,
	int index)
{
	char	*str;

	if (ft_check_options_history(arg, 'a', index) == 1)
		return (ft_run_history4(home, proc->histo2));
	if (ft_check_options_history(arg, 'n', index) == 1)
		return (ft_run_history5(arg, home, proc->histo2, index));
	if (ft_check_options_history(arg, 'r', index) == 1)
		return (ft_run_history5(arg, home, proc->histo2, index));
	if (ft_check_options_history(arg, 'w', index) == 1)
	{
		str = ft_strjoin(home, "/.42sh");
		ft_write_history_file2(proc->histo2, open(str, O_RDWR | O_TRUNC
		| O_CREAT, S_IRUSR | S_IWUSR), 1);
		free(str);
		return (1);
	}
	if (ft_check_options_history(arg, 's', index) == 1)
		ft_add_data(proc->histo2, arg + index + 2, 0);
	return (1);
}

int			ft_run_history(char *arg, char *home, t_prstruct *proc)
{
	int			index;

	if (home == NULL)
	{
		ft_putstr(" Please set the home variable of env to execute history");
		ft_putstr(" command \n");
		return (1);
	}
	index = 0;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
			arg[index] == '\n')
		index++;
	if (arg[index] >= '0' && arg[index] <= '9')
		return (ft_run_history2(arg, proc->histo2, index));
	else if (arg[index] == '\0')
		return (ft_display_list3(proc->histo2));
	if (arg[index] == '-')
		index++;
	if (ft_check_options_history(arg, 'c', index) == 1)
		return (ft_run_history_beta(proc));
	if (ft_check_options_history(arg, 'd', index) == 1)
		return (ft_run_history3(arg, proc->histo2, index));
	return (ft_run_history_part2(arg, home, proc, index));
}
