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

void	fill_matrix(char matrix[4][4], char *param)
{
	int		i;
	int		param_size;

	i = 0;
	param_size = ft_strlen(param);
	while (i < (param_size / 2) + 1)
	{
		matrix[i / 4][i % 4] = param[i * 2];
		i++;
	}
}

void	print_matrix(char matrix[4][4])
{
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c", matrix[i][j]);
			if (j < 3)
				printf(" - ");
			j++;
		}
		printf("\n");
		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	*param;
	char	external_matrix[4][4];

	if (argc != 2)
	{
		write(1, "Error: Missing argument\n", 25);
		return (1);
	}
	param = argv[1];
	if (check_parameter_errors(param))
	{
		write(1, "Error: bad param\n", 17);
		return (1);
	}
	else
		write(1, "no errors\n", 10);
	fill_matrix(external_matrix, param);
	print_matrix(external_matrix);
}
