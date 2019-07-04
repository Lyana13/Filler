/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:58:38 by lmalaya           #+#    #+#             */
/*   Updated: 2017/11/18 21:17:07 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*curr;
	t_list	*prev;

	head = NULL;
	prev = NULL;
	while (lst != NULL)
	{
		curr = f(lst);
		if (prev != NULL)
			prev->next = curr;
		else
			head = curr;
		prev = curr;
		lst = lst->next;
	}
	return (head);
}
