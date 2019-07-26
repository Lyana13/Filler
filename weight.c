/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:54:31 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/25 10:54:32 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	count_weight_enemy(t_board  *board, int re, int ce)
{
	int	c;
	int	r;
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
			if (state->board.cells[r * state->board.columns + c].symbol ==
				state->enemy_player ||
					state->board.cells[r * state->board.columns + c].symbol ==
					state->enemy_player + 32)
				count_weight_enemy(&(state->board), r, c);
			c++;
		}
		r++;
	}
}