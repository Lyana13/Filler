/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalaya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:03:16 by lmalaya           #+#    #+#             */
/*   Updated: 2019/07/25 11:03:18 by lmalaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_cell
{
	char		symbol;
	int			weight;
}				t_cell;

typedef struct	s_position
{	
	int			x;
	int			y;
	int			figure_weight;
}				t_position;

typedef struct s_figure
{
	char		*view;
	int 		columns;
	int 		rows;
	int 		columns_1;
	int 		rows_1;
}				t_figure;

typedef struct s_board
{
	t_cell		*cells;
	int 		columns;
	int 		rows;
}				t_board;

typedef struct s_filler
{
	char		my_player;
	char		enemy_player;
	t_board		board;
	t_figure	figure;
}				t_filler;

void    parse_figure(t_figure *figure);
void    parse_board(t_board *board);
void    parse_size(char *str, int *rows, int *cols);
void	find_weight_maps(t_filler *board);
void	count_weight_enemy(t_board  *board, int re, int ce);

int		module(int number);
int		max(int num_1, int num_2);
int		min(int num_1, int num_2);

#endif
