/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:30:42 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/10 17:42:47 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*fstr;
	int		i;
	int		j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char*)s);
		fstr = (char *)malloc(j * sizeof(char) + 1);
		if (fstr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			fstr[i] = f(s[i]);
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
