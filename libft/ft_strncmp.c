/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 00:52:59 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 21:55:23 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	int				i;

	if (n == 0)
		return (0);
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	i = 0;
	while (n-- && cs1[i] && cs2[i] && cs1[i] == cs2[i])
		if (n != 0)
			i++;
	return (cs1[i] - cs2[i]);
}
