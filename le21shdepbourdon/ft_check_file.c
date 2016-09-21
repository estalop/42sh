/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 22:56:35 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 16:28:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_check_file(char *path)
{
	struct stat		file_stat;

	if (stat(path, &file_stat) != 0)
		return (0);
	if (S_ISREG(file_stat.st_mode) != 1)
		return (0);
	return (access(path, F_OK | X_OK) == 0);
}
