/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:06:10 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/10 12:59:23 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	unsigned int	i;
	unsigned int	t;

	t = (unsigned char)c;
	i = 0;
	a1 = (unsigned char*)dst;
	a2 = (unsigned char*)src;
	while (i < n && a2[i] != t)
	{
		a1[i] = a2[i];
		i++;
	}
	if (i < n)
	{
		a1[i] = a2[i];
		return (dst + i + 1);
	}
	return (NULL);
}
