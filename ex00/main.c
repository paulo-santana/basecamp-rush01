/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:53:52 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/10 22:41:25 by vribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


void	create_external_matrix(char *param, int param_size)
{
	int		i;
	char	matrix[4][4];

	/* TODO: preencher a matriz*/
	i = param_size;

		matrix[i / 4][i % 4] = param[i * 2];
	/*return matrix; */
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
