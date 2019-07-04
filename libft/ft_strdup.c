/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:55:49 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/13 15:22:35 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*st;

	i = 0;
	while (s1[i])
		i++;
	if ((st = (char*)malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		st[i] = s1[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
