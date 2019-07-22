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
	fprintf(fptr, "\n\n\nfgfgf\n\n\n\n");
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

int main(int argc, char **argv)
{
	t_filler	state;
	t_position	position;
	char 		*str;
	int i = 0;

	
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
	fprintf(fptr, "row:%d, col: %d, dol: %c\n", state.board.rows, state.board.columns, state.board.cells[i].symbol);
	//free(str);
	fclose(fptr);
	return (0);
}