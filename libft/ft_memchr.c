/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:17:00 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 22:56:20 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	symb;

	mem = (unsigned char*)s;
	symb = (unsigned char)c;
	while (n--)
	{
		if (*mem == symb)
			return ((void*)mem);
		mem++;
	}
	return (NULL);
}
