#include "filler.h"

FILE 		*fptr;

int module(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

int max(int num_1, int num_2)
{
	return (num_1 > num_2 ? num_1 : num_2);
}

int min(int num_1, int num_2)
{
	return (num_1 < num_2 ? num_1 : num_2);
}

void	fill_weight_enemy(t_board  *board, int re, int ce)
{
	int c;
	int r;
	int fresh_weight;

	board->cells[re * board->columns + ce].weight = 0;
	r = 0;
	while (r < board->rows)
	{
		c = 0;
		while (c < board->columns)
		{
			fresh_weight = max(module(re - r), module(ce - c));
			board->cells[r * board->columns + c].weight =
			min(board->cells[r * board->columns + c].weight, fresh_weight);
			c++;
		}
		r++;
	}
}

void	find_weight_maps(t_filler *state)
{
	int	r;
	int	c;

	r = 0;
	while (r < state->board.rows)
	{
		c = 0;
		while (c < state->board.columns)
		{
			if (state->board.cells[r * state->board.columns + c].symbol == state->enemy_player ||
				state->board.cells[r * state->board.columns + c].symbol == state->enemy_player + 32)
				fill_weight_enemy(&(state->board), r, c);
			c++;
		}
		r++;
	}
}

void define_players(t_filler *state, char *program)
{
	char 		*str;
	int 		is_p1;

	get_next_line(0, &str);
	//fprintf(state->fptr, "%s\n", str);
	is_p1 = ft_strstr(str, "p1") && ft_strstr(str, program);
	state->my_player = is_p1 ? 'O' : 'X';
	state->enemy_player = is_p1 ? 'X' : 'O';
	free(str);
	//fprintf(state->fptr, "my: %c, ene: %c\n", state->my_player, state->enemy_player);
}

void	create_board(char *str, t_filler *state)
{
	parse_size(str, &(state->board.rows), &(state->board.columns));
	state->board.cells = (t_cell *)malloc((state->board.rows *
		state->board.columns) * sizeof(t_cell));
}

int	control_position(t_filler *state, int x, int y)
{
		int c;
		int r;
		t_cell point;
		int overlay;
		int figure_weight;

		figure_weight = 0;
		c = -1;
		overlay = 0;
		while (++c <= state->figure.columns_1)
		{
			r = -1;
			while (++r <= state->figure.rows_1)
			{
				if (state->figure.view[r * state->figure.columns + c] == '*')
				{
					point = state->board.cells[(y + r) * state->board.columns + (x + c)];
					if (point.symbol == state->enemy_player || 
						point.symbol == state->enemy_player + 32)
						return -1;
					else if (point.symbol == state->my_player || 
						point.symbol == state->my_player + 32)
						overlay++;
					figure_weight += point.weight;
				}
			}
		}
	return (overlay == 1 ? figure_weight : -1);
}

t_position decide_position(t_filler *state)
{
	int row;
	int col;
	int weight_figure;
	t_position right_position;

	right_position.figure_weight = 2147483647;
	col = -1;
	while (++col <= state->board.columns - state->figure.columns_1)
	{
		row = -1;
		while (++row <= state->board.rows - state->figure.rows_1)
		{
			if ((weight_figure = control_position(state, row, col)) != -1)
			{
				if (right_position.figure_weight > weight_figure)
				{
					right_position.x = row;
					right_position.y = col;
					right_position.figure_weight = weight_figure;
				}
			}
		}
	}
	return (right_position);
}

int main(int argc, char **argv)
{
	t_filler	state;
	t_position	position;
	char 		*str;
	int i = 0;
	char *x;
	char *y;


	fptr = fopen("./test.txt","w");
	(void)argc;
	ft_bzero(&state, sizeof(state));
	define_players(&state, argv[0]);
	while (get_next_line(0, &str))
	{
	 	if (state.board.cells == NULL)
			create_board(str, &state);
	 	free(str);
	 	parse_board(&(state.board));
	 	parse_figure(&(state.figure));
	 	find_weight_maps(&(state));
		position = decide_position(&(state));
		x = ft_itoa(position.x);
		y = ft_itoa(position.y);
		write(1, x, ft_strlen(x));
		write(1, " ", 1);
		write(1, y, ft_strlen(y));
		write(1, "\n", 1);
		free(x);
		free(y);
	 		fprintf(fptr, "figure %d\n x %d\n y %d\n", position.figure_weight,position.x, position.y);
	 		
	 	while(i < state.board.rows * state.board.columns){
	 		fprintf(fptr, "%3c", state.board.cells[i].symbol);
	 		i++;
	 		if (i % state.board.columns == 0)
	 			fprintf(fptr, "\n");
	 	}
	 	fprintf(fptr, "\n\n");
	 	i = 0;
	 	while (i < state.board.rows * state.board.columns)
	 	{
			fprintf(fptr, "%3s", ft_itoa(state.board.cells[i].weight));
			i++;
			if (i % state.board.columns == 0)
	 			fprintf(fptr, "\n");
	 	}
	 	i = 0;
	 	while(i < state.figure.rows * state.figure.columns){
	 		fprintf(fptr, "%c", state.figure.view[i]);
	 	i++;
	 	}
	 	free(state.figure.view);
	}
	//fprintf(fptr, "row:%d, col: %d, dol: %c\n", state.board.rows, state.board.columns, state.board.cells[i].symbol);
	free(str);
	fclose(fptr);
	return (0);
}
