/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 13:43:07 by jbobin            #+#    #+#             */
/*   Updated: 2016/01/07 14:26:44 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(int const fd, char **ptr)
{
	int		i;
	char	*c;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	if (!*ptr)
	{
		if ((*ptr = ft_strnew(1)) == NULL)
			return (-1);
	}
	while (!(c = ft_strchr(*ptr, '\n')) &&\
			(i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = *ptr;
		*ptr = ft_strjoin(tmp, buff);
		if (*ptr == NULL)
			return (-1);
		ft_strdel(&tmp);
	}
	if (i == -1)
		return (-1);
	if (c == NULL && i == 0)
		return (0);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char		*str;
	int				i;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	i = ft_get_line(fd, &str);
	if (i == -1)
		return (-1);
	if (i == 0)
	{
		if (str[0] != '\0')
		{
			*line = ft_strdup(str);
			ft_strdel(&str);
			return (1);
		}
		ft_strdel(&str);
		return (0);
	}
	*line = ft_strsub(str, 0, (ft_strchr(str, '\n') - str));
	tmp = str;
	str = ft_strdup(ft_strchr(tmp, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
