/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_check_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:27:14 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/01 20:44:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dlist		*ft_check_and_add_data(t_dlist *histo, char *total, int *pos,
	int *index)
{
	total[*index] = '\0';
	if (ft_strcmp(ft_get_element_from_list(histo, *pos), total) != 0)
	{
		if (*pos < 1 || *pos > histo->length)
			histo = ft_add_data(histo, total, 0);
		else
			histo = ins_avant(histo, total, histo->p_head, *pos);
	}
	*pos = *pos + 1;
	*index = 0;
	return (histo);
}

void		ft_get_check_file(t_dlist *histo, int fd, int index, int index2)
{
	int		ret;
	char	buf[11];
	char	total[4096];
	int		pos;

	pos = 1;
	if (fd == -1)
		return ;
	while ((ret = read(fd, buf, 10)))
	{
		buf[ret] = '\0';
		while (buf[index2] != '\0')
		{
			total[index] = buf[index2];
			if (total[index] == '\n')
				histo = ft_check_and_add_data(histo, total, &pos, &index);
			else
				index++;
			index2++;
		}
		index2 = 0;
	}
	close(fd);
}
