/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcscbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:34:12 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:34:13 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wcscbytes(int binsize)
{
	if (binsize <= 7)
		return (1);
	if (binsize <= 11)
		return (2);
	if (binsize <= 16)
		return (3);
	return (4);
}
