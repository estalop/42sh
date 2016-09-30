/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:08:05 by jbobin            #+#    #+#             */
/*   Updated: 2015/11/27 14:41:00 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_write(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_strwrite(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_write(str[i], fd);
		i++;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_strwrite("-214748364", fd);
		n = 8;
	}
	if (n < 0)
	{
		n = -n;
		ft_write('-', fd);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n < 10)
		ft_write(n + 48, fd);
}
