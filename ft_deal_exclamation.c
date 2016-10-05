/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_exclamation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:03:31 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/05 13:03:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_exclamation2(char *arg, t_dlist *histo)
{
	char	*str;
	int		index;

	index = 0;
	str = ft_get_element_from_list(histo, ft_atoi(arg) + 1);
	if (str == NULL)
	{
		ft_putstr("Event not found");
		return (arg);
	}
	while (str[index] != '\0')
	{
		if (str[index] == '!')
		{
			ft_putstr("This command is not available : you can\'t launch a");
			ft_putstr(" command containing \"!\" throught the current command");
			ft_putchar('\n');
			free(str);
			return (arg);
		}
		index++;
	}
	return (str);
}

char	*ft_exclamation3(char *arg, t_dlist *histo)
{
	char	*str;
	int		index;

	index = 0;
	str = ft_get_element_from_list(histo, histo->length + ft_atoi(arg));
	if (str == NULL)
	{
		ft_putstr("Event not found");
		return (arg);
	}
	while (str[index] != '\0')
	{
		if (str[index] == '!')
		{
			ft_putstr("This command is not available : you can\'t launch a");
			ft_putstr(" command containing \"!\" throught the current command");
			ft_putchar('\n');
			return (arg);
		}
		index++;
	}

	return (str);
}

char	*ft_exclamation5(char *arg, t_dlist *histo, int index)
{
	int		pos;

	pos = histo->length;
	while (pos > 0)
	{
		if (ft_strstr(ft_get_element_from_list(histo, pos), arg + index + 1) != NULL &&
			ft_strstr(ft_get_element_from_list(histo, pos), "!?") == NULL)
		{

				ft_putstr(ft_get_element_from_list(histo, pos));
				ft_putchar('\n');

			return (ft_get_element_from_list(histo, pos));
		}
		pos--;
		if (pos == 0)
		{

			return (arg);
		}
	}

	return (arg);
}

char	*ft_exclamation6(char *arg, t_dlist *histo, int index)
{
	int		pos;

	pos = histo->length;
	while (pos > 0)
	{
		if (ft_strncmp(ft_get_element_from_list(histo, pos), arg + index,
			ft_strlen(arg + index)) == 0)
		{

				ft_putstr(ft_get_element_from_list(histo, pos));
				ft_putchar('\n');

			return (ft_get_element_from_list(histo, pos));
		}
		pos--;
		if (pos == 0)
		{
			return (arg);
		}
	}
	return (arg);
}

char	*ft_check_excla(char *arg, t_prstruct *proc)
{
	int		index;

	index = 0;
	while (arg[index] == '\t' || arg[index] == ' ' || arg[index] == '\n')
		index++;
	if (arg[index] == '!')
		index++;
	if (arg[index] == '\0')
	{
		// dont understand what do I need to do
		return (arg);
	}
	if (arg[index] >= '0' && arg[index] <= '9')
		return (ft_exclamation2(arg + index, proc->histo2));
	if (arg[index] == '-' && arg[index + 1] >= '0' && arg[index + 1] <= '9')
		return (ft_exclamation3(arg + index, proc->histo2));
	if (arg[index] == '!')
		return (ft_exclamation3("-1", proc->histo2));
	if (arg[index] == '?')
		return (ft_exclamation5(arg, proc->histo2, index));
	return (ft_exclamation6(arg, proc->histo2, index));
}
