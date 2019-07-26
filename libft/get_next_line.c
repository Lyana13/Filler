/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:00:54 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/25 11:04:46 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				update_line(t_buff *buff, char **line, int *flag)
{
	char			*temp;

	if (*flag)
	{
		temp = ft_strjoin(*line, buff->pos);
		free(*line);
		*line = temp;
	}
	else
	{
		*line = ft_strdup(buff->pos);
		*flag = 1;
	}
}

int					work_with_buff(t_buff *buff, char **line, int *flag)
{
	char			*line_br;

	if (*(buff->pos))
	{
		if ((line_br = ft_strchr(buff->pos, '\n')))
		{
			*line_br = '\0';
			update_line(buff, line, flag);
			buff->pos = ++line_br;
			return (1);
		}
		else
			update_line(buff, line, flag);
	}
	return (0);
}

t_buff				*search_buff(int fd, t_list **head)
{
	t_buff			*buff;
	t_list			*node;

	node = *head;
	while (node)
	{
		buff = (t_buff*)(node->content);
		if (buff->fd == fd)
			return (buff);
		node = node->next;
	}
	buff = (t_buff*)malloc(sizeof(t_buff));
	buff->content = ft_strnew(BUFF_SIZE);
	buff->pos = buff->content;
	buff->fd = fd;
	ft_lstadd(head, ft_lstnew(buff, sizeof(t_buff)));
	free(buff);
	return ((t_buff*)(*head)->content);
}

void				del_buff(int fd, t_list **head)
{
	t_list			*prev;
	t_list			*curr;

	prev = NULL;
	curr = *head;
	while (((t_buff*)curr->content)->fd != fd)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!prev)
		*head = (*head)->next;
	else
		prev->next = curr->next;
	free(((t_buff*)curr->content)->content);
	free((t_buff*)curr->content);
	free(curr);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_buff			*buff;
	int				res;
	int				flag;

	flag = 0;
	if (fd < 0)
		return (-1);
	buff = search_buff(fd, &head);
	if (work_with_buff(buff, line, &flag))
		return (1);
	while ((res = read(fd, buff->content, BUFF_SIZE)))
	{
		if (res < 0)
			return (-1);
		if (res < BUFF_SIZE)
			buff->content[res] = '\0';
		buff->pos = buff->content;
		if (work_with_buff(buff, line, &flag))
			return (1);
	}
	del_buff(fd, &head);
	if (flag)
		return (1);
	return (0);
}
