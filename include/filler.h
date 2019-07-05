#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include "./libft/libft.h"

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct s_point
{
	int 		x;
	int 		y;
}				t_point;

typedef struct s_players
{
	int 		name;
	t_point 	start;
}				t_player;

typedef struct s_token
{
	int 		width;
	int 		height;
	int        	size;
	char 		**data;
}				t_token;

typedef struct s_filler
{
	int			initialize;
	t_player    player1;
	t_player	player2;
	t_point		target;
	t_token		board;
	t_token		token;
	t_point		*buff_f;
	int 			f_count;
	t_point 	*buff_t;
	ini 			t_count;
}					t_filler;