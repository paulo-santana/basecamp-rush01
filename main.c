/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/10 19:49:30 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* argument count, argument values */
int	main(int argc, char *argv[])
{
	int		i;
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

	if (param_size != 31)
	{
		write(1, "Error: wrong size\n", 18);
		return (1);
	}


	char matrix[4][4];

	i = 0;
	while (i < param_size / 2 + 1)
	{
		if (param[i * 2] < '1' || param[i * 2] > '4')
		{
			// write(1, "Error\n", 6);
			write(1, "Error: wrong char", 18);
			return (1);
		}
		matrix[i / 4][i % 4] = param[i * 2];
		i++;
	}

	for (i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c -", matrix[i][j]);
		}
	}

	write(1, "\n", 1);
}
