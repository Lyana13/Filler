/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:06:25 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/17 15:01:16 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *cdst;
	char *csrc;

	cdst = (char*)dst;
	csrc = (char*)src;
	if (cdst != csrc)
	{
		if (csrc < cdst)
			while (len--)
				cdst[len] = csrc[len];
		else
			while (len--)
				*cdst++ = *csrc++;
	}
	return (dst);
}
