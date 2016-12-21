/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_multiline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:31:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/21 09:43:58 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_history_multiline(char *tmp, t_termcaps *cap)
{
	int		i;
	char	*new;

	new = NULL;
	i = cap->prompt - cap->neg;
	ft_reset(cap, tmp);
	if (i > 0)
	{
		if (!(new = ft_strsub(tmp, 0, i)))
			return (NULL);
	}
	ft_strdel(&tmp);
	return (new);
}

int		ft_end_of_file(char *buf, t_termcaps *cap)
{
	char	*new;

	if (*buf == 4 && !cap->str && !cap->cmd)
		return (1);
	else if (*buf == 4 && cap->stop && \
	(!cap->str || cap->str[ft_strlen(cap->str) - 1] == '\n'))
	{
		new = ft_strjoin(cap->str, cap->stop);
		ft_strdel(&cap->str);
		cap->str = new;
		*buf = 10;
	}
	else if (*buf == 4)
		tputs(cap->bl, 0, ft_output);
	return (0);
}
