/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:27:38 by vribeiro          #+#    #+#             */
/*   Updated: 2021/04/10 22:49:12 by vribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
** Essa função testa se inicialmente a quantidade de caracteres
** presentes na cadeia é igual a 31.
** Após isso verifica se a cada valor par do iterador é um número
** dentre 1 e 4, e também verifica se a cada valor ímpar do iterador
** é um espaço. Se o teste falhar a função retorna "1", o que indica
** um erro. #TODO: printar uma mensagem de erro.
*/
int	verifica_parametros(char *param, int param_size)
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