#include "filler.h"

void define_players(t_filler *state, char *program)
{
	char 		*str;
	int 		is_p1;

	get_next_line(0, &str);
	fprintf(state->fptr, "%s\n", str);
	is_p1 = ft_strstr(str, "p1") && ft_strstr(str, program);
	state->my_player = is_p1 ? 'O' : 'X';
	state->enemy_player = is_p1 ? 'X' : 'O';
	fprintf(state->fptr, "my: %c, ene: %c\n", state->my_player, state->enemy_player);
}

int main(int argc, char **argv)
{
	t_filler	state;
	t_position	position;
	char 		*str;
	int 		i;
	
	state.fptr = fopen("./test.txt","w");
	i = 0;
	(void)argc;
	// get_next_line(0, &str);
	define_players(&state, argv[0]);
	
	
	while (get_next_line(0, &str))
	 {
	 	fprintf(state.fptr, "%s\n", str);
	 }
	//free(str);
	fclose(state.fptr);
	return (0);
}