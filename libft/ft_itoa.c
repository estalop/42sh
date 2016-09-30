/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:08:27 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/29 14:00:28 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countstrsize(int n)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (n == -2147483648 || n == 2147483647)
		return (10);
	if (n <= 0)
	{
		i = -i;
		while (i >= n)
		{
			i = i * 10;
			j++;
		}
	}
	else
	{
		while (i <= n && n != 2147483647)
		{
			i = i * 10;
			j++;
		}
	}
	return (j);
}

static int	ft_isn(int n, int i)
{
	int	j;

	j = i;
	if (n < 0)
		j++;
	return (j);
}

static char	*ft_fill(int n, int i, int j)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	if (j > i)
	{
		if (n == -2147483648)
		{
			n = n / 10;
			j--;
			str[j] = '8';
			i--;
		}
		n = -n;
	}
	while (i > 0)
	{
		i--;
		j--;
		str[j] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = ft_countstrsize(n);
	j = ft_isn(n, i);
	str = (char*)malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	free(str);
	str = ft_fill(n, i, j);
	if (n < 0)
		str[0] = '-';
	return (str);
}
