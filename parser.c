#include "filler.h"

void    parse_size(char *str, int *rows, int *cols)
{
    str = ft_strchr(str, ' ') + 1;
    *rows = ft_atoi(str);
    str = ft_strchr(str, ' ') + 1;
    *cols = ft_atoi(str);
}

void    parse_board(t_board *board)
{
	int     col_num;
	int     i;
	int     row_num;
	char    *str;

	get_next_line(0, &str);
	free(str);
	i = 0;
	row_num = 0;
	while (row_num < board->rows)
	{
		col_num = 4;
		get_next_line(0, &str);
		while (col_num < board->columns + 4)
        {
            board->cells[i].symbol = str[col_num++];
             board->cells[i++].weight = 2147483647;
        }
		free(str);
		row_num++;
	}
}

void    trim_rows(t_figure *figure)
{
    int     r;
    int     c;

    c = figure->columns;
    r = figure->rows - 1;
    while (r >= 0 && c == figure->columns)
    {
        c = 0;
        while (c < figure->columns)
            if (figure->view[r * figure->columns + c] == '*')
                break ;
            else
            	c++;
        r--;
    }
    figure->rows_1 = r + 2;
}

void    trim_columns(t_figure *figure)
{
    int     r;
    int     c;

    r = figure->rows;
    c = figure->columns - 1;
    while (c >= 0 && r == figure->rows)
    {
        r = 0;
        while(r < figure->rows)
            if(figure->view[r * figure->columns + c] == '*')
                break ;
            else
            	r++;
        c--;
    }
    figure->columns_1 = c + 2;
}

void    parse_figure(t_figure *figure)
{
    int     col_num;
    int     row_num;
    char    *str;


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
    trim_columns(figure);
    trim_rows(figure);
}
