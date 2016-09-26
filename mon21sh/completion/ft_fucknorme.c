/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fucknorme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:13:13 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/21 17:45:02 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fucknorm.h"

t_fnorm	ft_fucknorme(char *s1, char *s2, char *s3)
{
	t_fnorm	fnorm;

	fnorm.s1 = s1;
	fnorm.s2 = s2;
	fnorm.s3 = s3;
	return (fnorm);
}
