/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviviand <tviviand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:19:25 by tviviand          #+#    #+#             */
/*   Updated: 2016/04/20 18:19:26 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_binsize(long long int i)
{
	int n;

	n = 0;
	while (i)
	{
		i = i >> 1;
		n++;
	}
	return (n);
}
