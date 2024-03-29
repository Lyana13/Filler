/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:05:02 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/25 11:05:04 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_buff
{
	char		*content;
	char		*pos;
	int			fd;
}				t_buff;

int				get_next_line(const int fd, char **line);

#endif
