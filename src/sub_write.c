/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 10:59:45 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/14 14:49:20 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_calculate_length(char *str, int i, t_termcaps *cap, int val[4])
{
	while (str != NULL && str[val[2] - cap->neg] != '\0' && val[2] < i)
	{
		val[3] = str[val[2] - cap->neg] == '\t' ? 8 - (val[0] % 8) : 1;
		while (val[3]-- > 0)
		{
			if (str[val[2] - cap->neg] == '\n' && val[3] == 0)
			{
				val[1]++;
				val[0] = 0;
				val[3] = 0;
			}
			else if (val[0] >= (cap->whidth - 1))
			{
				val[1]++;
				val[0] = 0;
				val[3] = 0;
			}
			else
				val[0]++;
		}
		val[2]++;
	}
	return (val);
}
