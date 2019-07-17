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

int main(int argc, char **argv)
{
	t_filler	state;
	t_position	position;
	char 		*str;
	
	fptr = fopen("./test.txt","w");
	(void)argc;
	ft_bzero(&state, sizeof(state));
	define_players(&state, argv[0]);
	while (get_next_line(0, &str))
	{
	 	if (state.board.cells == NULL)
			create_board(str, &state); 
		
	 	fprintf(fptr, "%s\n", str);
	 	free(str);	
	}
	fprintf(fptr, "roww:%d, col: %d\n", state.board.rows, state.board.columns);
	//free(str);
	fclose(fptr);
	return (0);
}