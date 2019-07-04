/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:19:44 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/13 17:09:00 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const	char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (len > -1 && s[len] != (char)c)
		len--;
	if (len == -1)
		return (NULL);
	else
		return ((char*)(s + len));
}
