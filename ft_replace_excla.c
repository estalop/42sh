/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_excla.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:08:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/03 19:51:24 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_replace_excla(char *arg, t_prstruct *proc, int i)
{
	int		index;
	char	*str;
	int		index2;

	str = malloc(sizeof(char) * 4096);
	index = 0;
	index2 = 0;
	while (arg[index] != '\0')
	{
		if (arg[index] == '!')
		{
			str = ft_strjoin(str, ft_check_excla(arg + index, proc, i));
			index2 = index2 + ft_strlen(ft_check_excla(arg, proc, i));
			while (arg[index] != ' ' && arg[index] != '\0')
				index++;
			if (arg[index] == ' ')
			{
				str[index2] = arg[index];
				index2++;
			}
		}
		else
		{
			str[index2] = arg[index];
			index2++;
		}
		index++;
	}
	str[index2] = '\0';
	ft_putstr(" the final str is ");
	ft_putstr(str);
	ft_putchar('\n');
	return (str);
}
