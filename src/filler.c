#include "filler.h"

int main(void){
	t_filler	filler;
	char 		*line;

	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	filler.initialize = 0;
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10
		&& !ft_strncmp(line, "$$$ exec p", 9)
		&& line[10] == '1' || line[10] == '2'))
	{
		filler.player1.name = (line[10] == '1' ? 'O' : 'X');
		filler.player2.name = (line[10] == '1' ? 'X' : 'O');
		ft_strdel(&line);
		filler(filler);
	}
	else
		return (1);
	return (0);
}