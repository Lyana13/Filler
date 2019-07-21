#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct s_cell
{
	char	symbol;
	int		 weight;
}				t_cell;

typedef struct s_position
{	
	int			x;
	int			y;
	int			figure_weight;
}				t_position;

typedef struct s_figure
{
	char		*view;
	int 		columns;
	int 		rows;
	int 		columns_1;
	int 		rows_1;
}				t_figure;

typedef struct s_board
{
	t_cell		*cells;
	int 		columns;
	int 		rows;
}				t_board;

typedef struct s_filler
{
	char		my_player;
	char		enemy_player;
	t_board		board;
	t_figure	figure;
}					t_filler;

#endif