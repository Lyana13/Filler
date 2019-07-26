/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:11:41 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/25 12:04:21 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

FILE        *fptr;

void			define_players(t_filler *state, char *program)
{
	char		*str;
	int			is_p1;

	get_next_line(0, &str);
	is_p1 = ft_strstr(str, "p1") && ft_strstr(str, program);
	state->my_player = is_p1 ? 'O' : 'X';
	state->enemy_player = is_p1 ? 'X' : 'O';
	free(str);
}

void	create_board(char *str, t_filler *state)
{
	parse_size(str, &(state->board.rows), &(state->board.columns));
	state->board.cells = (t_cell *)malloc((state->board.rows *
		state->board.columns) * sizeof(t_cell));
}

int	check_char(t_filler *state, t_cell point, int *overlay)
{
	if (point.symbol == state->enemy_player ||
		point.symbol == state->enemy_player + 32)
		return (1);
	else if (point.symbol == state->my_player ||
		point.symbol == state->my_player + 32)
		(*overlay)++;
	return 0;
}

int				control_position(t_filler *state, int row, int col)
{
	int		c;
	int		r;
	t_cell	point;
	int		overlay;
	int		figure_weight;

	figure_weight = 0;
	c = -1;
	overlay = 0;
	while (++c < state->figure.columns_1)
	{
		r = -1;
		while (++r < state->figure.rows_1)
		{
			if (state->figure.view[r * state->figure.columns + c] == '*')
			{
				point = state->board.cells[(row + r) *
					state->board.columns + (col + c)];
				if (check_char(state, point, &overlay))
					return -1;
				figure_weight += point.weight;
			}
		}
	}
	return (overlay == 1 ? figure_weight : -1);
}

t_position		decide_position(t_filler *state)
{
	int			row;
	int			col;
	int			weight_figure;
	t_position	right_position;

	right_position.figure_weight = 2147483647;
	col = -1;
	fprintf(fptr, "\nx_max: %d y_max: %d\n", state->board.columns - state->figure.columns_1, state->board.rows - state->figure.rows_1);
	while (++col < state->board.columns - state->figure.columns_1)
	{
		row = -1;
		while (++row < state->board.rows - state->figure.rows_1)
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

int				main(int argc, char **argv)
{
	t_filler	state;
	t_position	position;
	char		*str;
	int			i;

	
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

		i = 0;
		while (i < state.board.rows * state.board.columns)
		{
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
		fprintf(fptr, "\nFIGURE c: %d, r: %d, c_1: %d, r_2: %d\n", state.figure.columns, state.figure.rows, state.figure.columns_1, state.figure.rows_1);
		i = 0;
		while (i < state.figure.rows * state.figure.columns)
		{
			fprintf(fptr, "%c", state.figure.view[i]);
			i++;
			if (i % state.figure.columns == 0)
				fprintf(fptr, "\n");
		}
		fprintf(fptr, "\nx: %d y: %d\n\n==================\n\n", position.x, position.y);
	
		// x = ft_itoa(position.x);
		// y = ft_itoa(position.y);
		// write(1, x, ft_strlen(x));
		// write(1, " ", 1);
		// write(1, y, ft_strlen(y));
		// write(1, "\n", 1);
		
	
	ft_putnbr(position.x);
	ft_putchar(' ');
	ft_putnbr(position.y);
	ft_putchar('\n');
	
		free(state.figure.view);
	}
	fclose(fptr);
	free(state.board.cells);
	return (0);
}

