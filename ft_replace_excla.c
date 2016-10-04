/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_excla.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:08:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/04 14:57:12 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_replace_excla(char *arg, t_prstruct *proc)
{
	int		index;
	char	*str;
	int		index2;
	char	*str2;
	int		index3;

	index = 0;
	index2 = 0;
	index3 = 0;
	str = malloc(sizeof(char) * 4096);
	while (arg[index] != '\0')
	{
		if (arg[index] == '!')
		{
			str2 = ft_check_excla(arg + index, proc);
			if (str2 != arg + index)
			{
				while (str2[index3] != '\0')
				{
					str[index2] = str2[index3];
					index2++;
					index3++;
				}
				while (arg[index] != '\0' && arg[index] != ' ' && arg[index] != '\t')
					index++;
				if (arg[index] == ' ' || arg[index] == '\t')
				{
					str[index2] = arg[index];
					index++;
					index2++;
				}
				index3 = 0;
				free(str2);
			}
			else
				index++;
		}
		else
		{
			str[index2] = arg[index];
			index2++;
			index++;
		}
	}
	return (str);
}
