/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 19:51:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/08/15 16:58:01 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_delete_space(char *arg)
{
	int		index;
	int		index2;
	char	*str;

	index2 = 0;
	str = malloc(sizeof(char) * ft_strlen(arg));
	index = 3;
	while (arg[index] == ' ' || arg[index] == '\t' || arg[index] == '\r' ||
		arg[index] == '\n')
		index++;
	while (arg[index] != '\0')
	{
		str[index2] = arg[index];
		index++;
		index2++;
	}
	str[index2] = '\0';
	return (str);
}
