/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_correct_entry.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:29:38 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 15:50:03 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_check_par(char *str)
{
	int		index;
	int		total;

	index = 0;
	total = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '(')
			total++;
		if (str[index] == ')' && total > 0)
			total--;
		index++;
	}
	return (total);
}

int		ft_check_quo(char *str)
{
	int		index;
	int		total;

	index = 0;
	total = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\'' && total == 0)
			total = 1;
		else if (str[index] == '\'' && total == 1)
			total = 0;
		index++;
	}
	return (total);
}

int		ft_check_cro(char *str)
{
	int		index;
	int		total;

	index = 0;
	total = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '[')
			total++;
		if (str[index] == ']' && total > 0)
			total--;
		index++;
	}
	return (total);
}

int		ft_check_acc(char *str)
{
	int		index;
	int		total;

	index = 0;
	total = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '{')
			total++;
		if (str[index] == '}' && total > 0)
			total--;
		index++;
	}
	return (total);
}

int		ft_check_correct_entry(t_dlist *list)
{
	char	*str;

	str = ft_get_str_from_list(list);
	if (ft_check_par(str) == 0 && ft_check_acc(str) == 0 &&
		ft_check_cro(str) == 0 && ft_check_quo(str) == 0 &&
		ft_check_dquo(str) == 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
