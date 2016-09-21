/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:24:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/22 17:24:35 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

char			*ft_strcup(char *arg)
{
	int		index2;
	int		index;
	char	*str;

	index2 = 0;
	index = 0;
	str = malloc(sizeof(char) * ft_strlen(arg) + 1);
	while (arg[index2] != '\0' && arg[index2] != ' ' && arg[index2] != '\t'
		&& arg[index2] != '\n' && arg[index2] != '=')
	{
		str[index] = arg[index2];
		index2++;
		index++;
	}
	str[index] = '=';
	index++;
	str[index] = '\0';
	return (str);
}
