/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucknorm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:15:30 by tbayet            #+#    #+#             */
/*   Updated: 2016/09/21 18:19:03 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUCKNORM_H
# define FUCKNORM_H

typedef struct	s_fnorm
{
	char		*s1;
	char		*s2;
	char		*s3;
}				t_fnorm;

t_fnorm			ft_fucknorme(char *s1, char *s2, char *s3);

#endif
