/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:48:10 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 23:09:17 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *max, unsigned int len)
{
	unsigned int	i;
	int				t;

	if (len == 0)
		return (0);
	t = max[0];
	i = 1;
	while (i < len)
	{
		if (t < max[i])
			t = max[i];
		i++;
	}
	return (0);
}
