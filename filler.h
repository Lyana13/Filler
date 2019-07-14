#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct s_area
{
	char	symbol;
	int		 weight;
}				t_area;

typedef struct s_position
{	
	int			x;
	int			y;
	int			figure_weight;
}				t_position;

typedef struct s_figures
{
	char		*view;
	int 		col;
	int 		row;
}				t_figures;

typedef struct s_maps
{
	t_area		*area;
	int 		col;
	int 		row;
}				t_maps;

typedef struct s_filler
{
	char		my_player;
	char		enemy_player;
	t_maps		map;
	t_figures	figure;
	FILE 		*fptr;
}					t_filler;

#endif