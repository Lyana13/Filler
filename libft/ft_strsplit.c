/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:58:22 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 22:08:59 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		o;
	int		j;
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && ++i)
			continue ;
		tab[j] = (char*)malloc(ft_count_letters(s + 1, c) + 1);
		o = 0;
		while (s[i] != c && s[i] != '\0')
			tab[j][o++] = s[i++];
		tab[j++][o] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}
