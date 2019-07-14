/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:02:40 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/10 13:17:04 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ssrc;
	char	*ddst;
	size_t	i;

	ssrc = (char*)src;
	ddst = (char*)dst;
	i = 0;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	return (dst);
}
