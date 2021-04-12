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

int valid_ones = 0;

int is_solved(int internal_matrix[4][4], int external_matrix[4][4])
{
	valid_ones++;
	int	is_top_valid;
	int	is_bottom_valid;
	int	is_left_valid;
	int	is_right_valid;

	is_top_valid = validate_top_to_bottom(internal_matrix, external_matrix[0]);
	is_bottom_valid = validate_bottom_to_top(internal_matrix, external_matrix[1]);
	is_left_valid = validate_left_to_right(internal_matrix, external_matrix[2]);
	is_right_valid = validate_right_to_left(internal_matrix, external_matrix[3]);

	printf("t, b, l, r: %d %d %d %d\n", is_top_valid, is_bottom_valid, is_left_valid, is_right_valid);
	if (is_top_valid && is_bottom_valid && is_left_valid && is_right_valid)
		return (1);
	return (0);
}
int	fill_internal_matrix(int matrix[4][4], int external_matrix[4][4])
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
	    while(cursor_coluna < 4)
	    {
			//printf("linha, coluna: [%d, %d]\n", cursor_linha, cursor_coluna);
	        placed = 0;
			if (came_back)
				n = matrix[cursor_linha][cursor_coluna];
			else
				n = 0;
    		while (++n < 5)
    			if (can_place(n, matrix, cursor_linha, cursor_coluna))
    			{
    				matrix[cursor_linha][cursor_coluna] = n;
    				placed = 1;
    				break;
    			}
    		if (!placed) 
			{
				if (cursor_coluna == 0 && cursor_linha == 0)
					return(0);
    		    if (cursor_coluna == 0)
    		    {
    		        cursor_coluna = 3;
    		        cursor_linha--;
    		    }
    		    else
    		    {
    		        cursor_coluna--;
    		    }
				came_back = 1;
			}
        	else if (cursor_coluna == 3 && cursor_linha == 3)
			{

				printf("nova matriz:\n");
				//print_matrix(matrix);
				if (is_solved(matrix, external_matrix))
					return (1);
				else
					if (cursor_coluna == 0)
					{
						cursor_coluna = 3;
						cursor_linha--;
					}
					else
					{
						cursor_coluna--;
					}
				came_back = 1;
			}
			else
			{
				came_back = 0;
				cursor_coluna++;
			}
	    }
		came_back = 0;
	    cursor_linha++;
	}
	
	return (0);
	
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
	print_matrix(external_matrix);

	if (!is_board_valid(external_matrix))
	{
		write(1, "Error: bad board\n", 17);
		return (1);
	}

	if (fill_internal_matrix(internal_matrix, external_matrix))
		printf("solved\n");
	else
		printf("not solved\n");
	printf("valid ones: %d\n", valid_ones);
	//print_matrix(internal_matrix);
}
