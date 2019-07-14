/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:18:54 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/17 15:05:37 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr_el;
	t_list	*next_el;

	curr_el = *alst;
	while (curr_el != NULL)
	{
		next_el = curr_el->next;
		del(curr_el->content, curr_el->content_size);
		free(curr_el);
		curr_el = next_el;
	}
	*alst = NULL;
}
