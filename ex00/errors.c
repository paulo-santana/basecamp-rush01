/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:27:38 by vribeiro          #+#    #+#             */
/*   Updated: 2021/04/11 02:29:24 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
** Essa função testa se inicialmente a quantidade de caracteres
** presentes na cadeia é igual a 31.
** Após isso verifica se a cada valor par do iterador é um número
** dentre 1 e 4, e também verifica se a cada valor ímpar do iterador
** é um espaço. Se o teste falhar a função retorna "1", o que indica
** um erro. #TODO: printar uma mensagem de erro.
*/

int	is_parameter_valid(char *param)
{
	unsigned int	i;
	unsigned int	param_size;

	i = 0;
	param_size = ft_strlen(param);
	if (param_size != 31)
		return (0);
	while (i < param_size)
	{
		if (i % 2 == 0)
		{
			if (param[i] < '1' || param[i] > '4')
				return (1);
		}
		else if (param[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
