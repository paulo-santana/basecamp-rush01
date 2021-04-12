/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/11 14:32:06 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "functions.h"
#include <stdio.h>

/*
** Preenche a matriz externa com os valores enviados no parametro
** A disposicao da matriz fica da seguinte forma:
** matrix[0][X] = colXup
** matrix[1][X] = colXdown
** matrix[2][X] = rowXleft
** matrix[3][X] = rowXright
*/
int	g_outer_matrix[4][4];
int	g_inner_matrix[4][4];

void	fill_external_matrix(char *param)
{
	unsigned int	i;
	unsigned int	param_size;

	i = 0;
	param_size = ft_strlen(param);
	while (i < (param_size / 2) + 1)
	{
		g_outer_matrix[i / 4][i % 4] = param[i * 2] - '0';
		i++;
	}
}

int		can_place(int number, int linha, int coluna)
{
	int i;
	int j;

	i = -1;
	while (++i < linha)
		if (g_inner_matrix[i][coluna] == number)
			return (0);
	j = -1;
	while (++j < coluna)
		if (g_inner_matrix[linha][j] == number)
			return (0);
	return (1);
}

int		is_solved()
{
	int	is_top_valid;
	int	is_bottom_valid;
	int	is_left_valid;
	int	is_right_valid;

	is_top_valid = validate_top_to_bottom(g_inner_matrix, g_outer_matrix[0]);
	is_bottom_valid = validate_bottom_to_top(g_inner_matrix, g_outer_matrix[1]);
	is_left_valid = validate_left_to_right(g_inner_matrix, g_outer_matrix[2]);
	is_right_valid = validate_right_to_left(g_inner_matrix, g_outer_matrix[3]);
	if (is_top_valid && is_bottom_valid && is_left_valid && is_right_valid)
		return (1);
	return (0);
}

void	go_back(int *coluna, int *linha)
{
	if (*coluna == 0)
	{
		*coluna = 3;
		*linha = *linha - 1;
	}
	else
	{
		*coluna = *coluna - 1;
	}
}

int		check_board(int *placed, int *coluna, int *linha, int *came_back)
{
	if (!(*placed))
	{
		if (*coluna == 0 && *linha == 0)
			return (0);
		go_back(coluna, linha);
		*came_back = 1;
	}
	else if (*coluna == 3 && *linha == 3)
	{
		if (is_solved())
		{
			return (1);
		}
		else
		{
			go_back(coluna, linha);
		}
		*came_back = 1;
	}
	else
	{
		*came_back = 0;
		(*coluna)++;
	}
	return (0);
}

int		fill_internal_matrix(int matrix[4][4])
{
	int cursor_linha;
	int cursor_coluna;
	int n;
	int placed;
	int came_back;

	placed = 0;
	came_back = 0;
	cursor_linha = 0;
	cursor_coluna = 0;
	while (cursor_linha < 4)
	{
		cursor_coluna = 0;
		while (cursor_coluna < 4)
		{
			placed = 0;
			if (came_back)
				n = matrix[cursor_linha][cursor_coluna];
			else
				n = 0;
			while (++n < 5)
				if (can_place(n, cursor_linha, cursor_coluna))
				{
					matrix[cursor_linha][cursor_coluna] = n;
					placed = 1;
					break ;
				}
			if (check_board(&placed, &cursor_coluna, &cursor_linha, &came_back))
			{
				return (1);
			}
		}
		came_back = 0;
		cursor_linha++;
	}
	return (0);
}

void	print_matrix(int matrix[4][4])
{
	int		i;
	int		j;
	char	num;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			num = matrix[i][j] + '0';
			write(1, &num, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	*param;

	if (argc != 2)
	{
		write(1, "Error: Missing argument\n", 25);
		return (1);
	}
	param = argv[1];
	if (!is_parameter_valid(param))
	{
		write(1, "Error: bad param\n", 17);
		return (1);
	}
	fill_external_matrix(param);
	if (!is_board_valid(g_outer_matrix))
	{
		write(1, "Error: bad board\n", 17);
		return (1);
	}
	if (!fill_internal_matrix(g_inner_matrix))
		write(2, "Error\n", 6);
	print_matrix(g_inner_matrix);
}
