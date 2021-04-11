/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/11 02:36:54 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "functions.h"

/*
** TODO: preencher a matriz
*/

void	create_external_matrix(char *param, int param_size)
{
	int		i;
	char	matrix[4][4];

	i = 0;
	matrix[i / 4][i % 4] = param[i * 2];
	return (matrix);
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
	if (check_parameter_errors(param))
	{
		write(1, "Error: bad param\n", 17);
		return (1);
	}
	else
		write(1, "no errors\n", 10);
}
