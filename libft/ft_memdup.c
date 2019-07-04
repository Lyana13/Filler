/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:41:07 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 23:06:53 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *p, size_t size)
{
	void	*new;
	size_t	i;

	i = 0;
	new = malloc(size);
	while (i < size)
	{
		((char*)new)[i] = ((char*)p)[i];
		i++;
	}
	return (new);
}
