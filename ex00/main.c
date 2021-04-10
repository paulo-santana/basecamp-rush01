/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/10 22:18:38 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


int	has_errors(char *param, int param_size)
{
	int	i;

	i = 0;
	if (param_size != 31)
		return (1);
	while (i < param_size)
	{
		if (i % 2 == 0)
		{
			if (param[i] < '1' || param[i] > '4')
				return (1);
		}
		else
			if (param[i] != ' ')
				 return (1);
		i++;
	}
	return (0);
}

void	create_external_matrix(char *param, int param_size)
{
	int		i;
	char	matrix[4][4];

	// TODO: preencher a matriz
	i = param_size;

		matrix[i / 4][i % 4] = param[i * 2];
	//eturn matrix;
}

/* argument count, argument values */
int	main(int argc, char *argv[])
{
	//int		i;
	int		param_size;
	char	*param;

	if (argc != 2)
	{
		write(1, "Error: Missing argument\n", 25);
		return (1);
	}
	param = argv[1];
	param_size = 0;
	while (param[param_size] != '\0')
		param_size++;
	if (has_errors(param, param_size))
	{
		write(1, "Error: bad param\n", 17);
		return (1);
	}
	else
		write(1, "no errors\n", 10);
}
