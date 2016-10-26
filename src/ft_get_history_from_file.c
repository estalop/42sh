/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_file_history.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 15:00:47 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/26 16:18:32 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_get_history_from_file(t_dlist *histo, int fd)
{
	char	*total;

	if (fd == -1)
		return ;
	while (get_next_line(fd, &total))
		ft_add_data(histo, total, 1);
	close(fd);
}
