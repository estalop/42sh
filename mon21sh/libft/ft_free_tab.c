/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 13:02:16 by jbobin            #+#    #+#             */
/*   Updated: 2016/04/08 13:03:06 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_free_tab(char ***argv)
{
	int		i;
	char	**tmp;

	tmp = *argv;
	i = 0;
	if (*argv != NULL && tmp != NULL)
	{
		while (tmp[i] != NULL)
		{
			ft_strdel(&tmp[i]);
			i++;
		}
		free(tmp);
	}
	*argv = NULL;
}
