/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:47:32 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 23:04:58 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *str, char c)
{
	int	word;
	int i;

	if (str == NULL)
		return (0);
	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			word++;
		while (str[i] != c && str[i] != '\0')
			i++;
		i++;
	}
	return (word);
}
