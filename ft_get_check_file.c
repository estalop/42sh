/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_check_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:27:14 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/30 15:49:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_check_and_add_data(t_dlist *histo, char *total, int pos)
{
	ft_putstr(total);
	if (ft_strcmp(ft_get_element_from_list(histo, pos), total) != 0)
	{
		ft_putstr(" is added at ");
		ft_putnbr(pos);
		ins_avant(histo, total, histo->p_head, pos);
	}
	ft_putchar('\n');
}

void		ft_get_check_file(t_dlist *histo, int fd, int index, int index2)
{
	int		ret;
	char	buf[11];
	char	total[4096];
	int		pos;

	ft_putstr(" on commence a analyser\n");
	pos = 1;
	if (fd == -1)
		return;
	while ((ret = read(fd, buf, 10)))
	{
		buf[ret] = '\0';
		while (buf[index2] != '\0')
		{
			total[index] = buf[index2];
			if (total[index] == '\n')
			{
				total[index] = '\0';
				index = 0;
				ft_check_and_add_data(histo, total, pos);
				pos++;
			}
			else
				index++;
			index2++;
		}
		index2 = 0;
	}
	close(fd);
}
