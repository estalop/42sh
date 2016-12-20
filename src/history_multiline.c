/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_multiline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:31:30 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/20 14:26:57 by jbobin           ###   ########.fr       */
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
