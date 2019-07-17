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