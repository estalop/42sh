/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:36:23 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/27 14:41:30 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_write(char c)
{
	write(1, &c, 1);
}

static void	ft_strwrite(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_write(str[i]);
		i++;
	}
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_strwrite("-214748364");
		n = 8;
	}
	if (n < 0)
	{
		n = -n;
		ft_write('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
		ft_write(n + 48);
}
