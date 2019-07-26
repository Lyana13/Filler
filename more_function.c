/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:38:33 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/25 19:38:36 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		module(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

int		max(int num_1, int num_2)
{
	return (num_1 > num_2 ? num_1 : num_2);
}

int		min(int num_1, int num_2)
{
	return (num_1 < num_2 ? num_1 : num_2);
}
