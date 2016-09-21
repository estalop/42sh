/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_home.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:22:55 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:50:51 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_error_home2(char *tmp2)
{
	ft_putstr(" A problem just happened, you need to add the home environment");
	ft_putstr(" variable to perform this operation\n");
	free(tmp2);
	return (1);
}

char	**ft_error_home(void)
{
	ft_putstr(" A problem just happened, you need to add the home environment");
	ft_putstr(" variable to perform this operation\n");
	return (NULL);
}
