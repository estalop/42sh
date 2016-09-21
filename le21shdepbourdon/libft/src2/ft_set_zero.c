/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 21:02:03 by pbourdon          #+#    #+#             */
/*   Updated: 2016/07/28 21:04:54 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_set_zero(int index, char **options)
{
	int		index2;

	index2 = 0;
	while (index2 <= index)
	{
		options[index2] = NULL;
		index2++;
	}
	return (options);
}
