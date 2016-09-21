/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 23:18:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/16 01:01:41 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*read_alpha(int const fd, char *tmp, int *check)
{
	char		tmp2[BUFF_SIZE + 1];
	char		*tmp3;

	*check = read(fd, tmp2, BUFF_SIZE);
	tmp2[*check] = '\0';
	tmp3 = ft_strjoin(tmp, tmp2);
	free(tmp);
	return (tmp3);
}

int				save_lines(int *check, char **tmp, int const fd, char **line)
{
	char		tmp2[BUFF_SIZE + 1];

	*check = 1;
	if (fd < 0 || line == NULL || read(fd, tmp2, 0) < 0)
		return (1);
	if (!*tmp)
	{
		*tmp = malloc(sizeof(1));
		if (*tmp)
			*tmp[0] = '\0';
		else
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line, int check)
{
	static char		*tmp;
	char			*cursor;

	if (save_lines(&check, &tmp, fd, line))
		return (-1);
	while (check > 0)
	{
		if ((cursor = ft_strchr(tmp, '\n')) != NULL)
		{
			*cursor = '\0';
			*line = ft_strdup(tmp);
			ft_memmove(tmp, cursor + 1, ft_strlen(cursor + 1) + 1);
			return (1);
		}
		tmp = read_alpha(fd, tmp, &check);
	}
	if (tmp != (cursor = ft_strchr(tmp, '\0')))
	{
		*line = ft_strdup(tmp);
		ft_memmove(tmp, cursor + 1, ft_strlen(cursor + 1) + 1);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (check);
}
