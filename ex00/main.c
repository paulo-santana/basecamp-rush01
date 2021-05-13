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
void	fill_external_matrix(int matrix[4][4], char *param)
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

int	can_place(int board[4][4], int number, int linha, int coluna)
{
	int	i;
	int	j;

	if (number > 4)
		return (0);
	if (linha == 0 && coluna == 0)
		return (1);
	if (board[0][0] == 0)
		return (0);
	if (board[linha][coluna] == number)
		return (0);
	i = -1;
	while (++i < linha)
		if (board[i][coluna] == number)
			return (0);
	j = -1;
	while (++j < coluna)
		if (board[linha][j] == number)
			return (0);
	return (1);
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

int	main(int argc, char *argv[])
{
	char	*param;
	int		views[4][4];

	if (argc != 2)
	{
		ft_puterr("Error\n");
		return (3);
	}
	param = argv[1];
	if (!is_parameter_valid(param))
	{
		ft_puterr("Error\n");
		return (2);
	}
	fill_external_matrix(views, param);
	if (!solve(views))
	{
		ft_puterr("Error\n");
		return (1);
	}
	return (0);
}
