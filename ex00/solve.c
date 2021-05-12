#include "functions.h"
#include <stdio.h>

/*
** Tries to solve a board with outer_matrix constraints.
** Returns 1 if a solution for these constraints was found, 0 otherwise.
*/

int	solve(int outer_matrix[4][4])
{
	int	board[4][4];
	int	i;

	i = -1;
	while (++i < 16)
		board[i / 4][i % 4] = 0;
	while (!is_solved(board, outer_matrix))
	{
		if (!find_next(board))
			return (0);
	}
	print_matrix(board);
	return (1);
}

int	is_solved(int board[4][4], int views[4][4])
{
	int	is_top_valid;
	int	is_bottom_valid;
	int	is_left_valid;
	int	is_right_valid;

	is_top_valid = validate_top_to_bottom(board, views[0]);
	is_bottom_valid = validate_bottom_to_top(board, views[1]);
	is_left_valid = validate_left_to_right(board, views[2]);
	is_right_valid = validate_right_to_left(board, views[3]);
	if (is_top_valid && is_bottom_valid && is_left_valid && is_right_valid)
		return (1);
	return (0);
}

/*
** Find the next iteration of a board that would be a valid board.
** If the first cell of the board is 0, then it will actually find the first
** valid board.
*/

int	find_next(int board[4][4])
{
	int	cursor;
	int	number;
	int	could_place;

	cursor = 15;
	number = 1;
	while (cursor >= 0 && cursor < 16)
	{
		could_place = can_place(board, number, cursor / 4, cursor % 4);
		if (could_place)
		{
			board[cursor / 4][cursor % 4] = number;
			cursor++;
			number = 1;
		}
		else if (board[0][0] && number < 4)
			number++;
		else
		{
			board[cursor / 4][cursor % 4] = 0;
			cursor--;
			number = board[cursor / 4][cursor % 4] + 1;
		}
	}
	return (could_place);
}
