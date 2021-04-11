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
#include <stdio.h>
#include "functions.h"

/*
** Preenche a matriz externa com os valores enviados no parametro
** A disposicao da matriz fica da seguinte forma:
** matrix[0][X] = colXup
** matrix[1][X] = colXdown
** matrix[2][X] = rowXleft
** matrix[3][X] = rowXright
*/

void	fill_matrix(int matrix[4][4], char *param)
{
	unsigned int	i;
	unsigned int	param_size;

	i = 0;
	param_size = ft_strlen(param);
	while (i < (param_size / 2) + 1)
	{
		matrix[i / 4][i % 4] = param[i * 2] - '0';
		i++;
	}
}

void	print_matrix(int matrix[4][4])
{
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c", matrix[i][j] + '0');
			if (j < 3)
				printf(" - ");
			j++;
		}
		printf("\n");
		i++;
	}
}
int		can_place(int number, int matrix[4][4], int cursor_linha, int cursor_coluna)
{
	int i;
	int j;

	i = -1;
	while (++i < cursor_linha)
		if (matrix[i][cursor_coluna] == number)
			return (0);
	j = -1;
	while (++j < cursor_coluna)
		if (matrix[cursor_linha][j] == number)
			return (0);
	return 1;
}
void	fill_internal_matrix(int matrix[4][4], int external_matrix[4][4])
{
	int cursor_linha;
	int cursor_coluna;
	int n;

	cursor_linha = 0;
	cursor_coluna = 0;
	while (matrix[0][0] != 2)
	{
		n = 0;
		while (++n < 5)
			if (can_place(n, matrix, cursor_linha, cursor_coluna))
			{
				matrix[cursor_linha][cursor_coluna] = n;
			}
			else
			{
				if (matrix[cursor_linha][cursor_coluna] < 4)
				{
					matrix[cursor_linha][cursor_coluna]++;
					if (cursor_coluna == 3)
					{
						cursor_coluna = 0;
						cursor_linha++;
					}
					else
						cursor_coluna++;
				}
				else
				{
					if (cursor_coluna == 0)
					{
						cursor_coluna = 3;
						cursor_linha--;
					}
					else
						cursor_coluna--;
				}
			}
	}
//	if (!is_solved(matrix, external_matrix))
//	{
//
//	}
}

int		main(int argc, char *argv[])
{
	char	*param;
	int		external_matrix[4][4];
	int		internal_matrix[4][4];

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
	else
		write(1, "no errors\n", 10);
	fill_matrix(external_matrix, param);
	if (!is_board_valid(external_matrix))
	{
		write(1, "Error: bad board\n", 17);
		return (1);
	}

	fill_internal_matrix(internal_matrix, external_matrix);
	print_matrix(internal_matrix);
}
