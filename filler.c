#include "filler.h"

FILE 		*fptr;

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

void		parse_size(char *str, int *rows, int *cols)
{
	str = ft_strchr(str, ' ') + 1;
	*rows = ft_atoi(str);
	str = ft_strchr(str, ' ') + 1;
	*cols = ft_atoi(str);
}

void	create_board(char *str, t_filler *state)
{
	parse_size(str, &(state->board.rows), &(state->board.columns));
	state->board.cells = (t_cell *)malloc((state->board.rows *
		state->board.columns) * sizeof(t_cell));
}

void fill_board(t_board *board)
{
	int col_num;
	int i;
	int row_num;
	char 		*str;

	get_next_line(0, &str);
	free(str);
	i = 0;
	row_num = 0;
	while (row_num < board->rows)
	{
		col_num = 4;
		get_next_line(0, &str);
		while (col_num < board->columns + 4)
			 board->cells[i++].symbol = str[col_num++];
		free(str);
		row_num++;
	}
}

void trim_figure(t_figure *figure)
{
	int r;
	int c;

	r = figure->rows;
	c = figure->columns - 1;
	while (c > 0 && r == figure->rows)
	{
		r = 0;
		while(r < figure->rows)
			if(figure->view[r++ * figure->columns + c] != '*')
				break ;
	}
	figure->columns_1 = c + 1;
}

void	fill_figure(t_figure *figure)
{
	int col_num;
	int row_num;
	char *str;

	get_next_line(0, &str);
	parse_size(str, &(figure->rows), &(figure->columns));
	free(str);
	row_num = 0;
	figure->view = (char *)malloc((figure->rows * figure->columns) *
		sizeof(char));
	while (row_num < figure->rows)
	{
		get_next_line(0, &str);
		col_num = 0;
		while (col_num < figure->columns)
		{
			figure->view[row_num * figure->columns + col_num] = str[col_num];
			col_num++;
		}
		free(str);
		row_num++;
	}
	trim_figure(figure);
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
	 	fill_board(&(state.board));
	 	fill_figure(&(state.figure));
	 	while(i < state.board.rows * state.board.columns){
	 		fprintf(fptr, "%c", state.board.cells[i].symbol);
	 	i++;
	 	}
	 	fprintf(fptr, "\n\n");
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