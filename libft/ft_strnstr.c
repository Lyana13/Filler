/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:58:41 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/17 15:21:14 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const	char *big, const	char *ltl, size_t len)
{
	size_t	len2;

	if (ltl[0] == '\0')
		return ((char *)big);
	len2 = ft_strlen(ltl);
	while (*big && len-- >= len2)
	{
		if (*big == *ltl && ft_memcmp(big, ltl, len2) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
