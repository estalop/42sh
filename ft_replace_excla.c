/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_excla.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 19:08:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/06 15:16:12 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_count_malloc(char *arg, t_prstruct *proc)
{
	int		index;
	int		compteur;

	index = 0;
	compteur = ft_strlen(arg);
	while (arg[index] != '\0')
	{
		if (arg[index] == '!')
		{
			compteur += ft_strlen(ft_check_excla(arg + index, proc));
		}
		index++;
	}
	return (compteur);
}

static void		ft_replace_excla2(char **str, int *index2, char *arg, int
	*index)
{
	while (arg[*index] != '\0' && arg[*index] != ' ' && arg[*index] != '\t')
		*index = *index + 1;
	if (arg[*index] == ' ' || arg[*index] == '\t')
	{
		*str[*index2] = arg[*index];
		*index = *index + 1;
		*index2 = *index2 + 1;
	}
}

static char		*ft_replace_excla3(char *str, int *index2, char *str2)
{
	int		index3;

	index3 = 0;
	while (str2[index3] != '\0')
	{
		str[*index2] = str2[index3];
		*index2 = *index2 + 1;
		index3++;
	}
	free(str2);
	return (str);
}

char			*ft_replace_excla(char *arg, t_prstruct *proc, int index,
	int index2)
{
	char	*str;
	char	*str2;

	str = malloc(sizeof(char) * (ft_count_malloc(arg, proc) + 10));
	while (arg[index] != '\0')
	{
		if (arg[index] == '!')
		{
			str2 = ft_check_excla(arg + index, proc);
			if (str2 != arg + index)
			{
				str = ft_replace_excla3(str, &index2, str2);
				ft_replace_excla2(&str, &index2, arg, &index);
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
