/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:29:48 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/13 17:37:22 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ret_the_number(long long num, int j, int flag)
{
	if (flag == 1)
		num = -num;
	if ((j > 19) && (flag == 1))
		return (0);
	else if ((j > 19) && (flag == 0))
		return (-1);
	if (flag == 1)
		return (-num);
	return (num);
}

int				ft_atoi(const char *str)
{
	size_t		i;
	long long	num;
	int			flag;
	int			j;

	i = 0;
	num = 0;
	flag = 0;
	j = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			flag = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + (str[i] - '0');
		j++;
		i++;
	}
	num = ret_the_number(num, j, flag);
	if (flag == 1)
		return (-num);
	return (num);
}
