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

typedef struct s_part
{
	char 		**data;
	int 		width;
	int 		height;
}				t_part;

typedef struct s_map
{
	int 		row;
	int 		col;
}				t_map;

typedef struct s_filler
{
	t_player    player1;
	t_player	player2;
	t_point		target;
	t_token		board;
	t_part		token;
	t_map		*map;
}					t_filler;

#endif