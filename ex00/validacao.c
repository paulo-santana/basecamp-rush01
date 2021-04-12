/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validacao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:51:15 by vribeiro          #+#    #+#             */
/*   Updated: 2021/04/12 00:41:51 by vribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validate_top_to_bottom(int matriz[4][4]) 
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	coluna = 0;
	while(coluna < 4)
	{
		visao = matriz[0][coluna];
		cursor = 0;
		linha = 0;
		while(linha < 4)
		{
			if(cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			linha++;
		}
		coluna++;
		if(visao != 0)
			return(0);
	}
	return(1);
}

int		validate_bottom_to_top(int matriz[4][4])
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	coluna = 3;
	while(coluna >= 0)
	{
		visao = matriz[3][coluna];
		cursor = 0;
		linha = 3;

		while(linha >= 0)
		{
			if (cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			linha--;
		}
		coluna--;
		if (visao != 0)
			return (0);
	}
	return (1);
}


int		validate_left_to_right(int matriz[4][4]) 
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	linha = 0;
	while(linha < 4)
	{
		visao = matriz[linha][0];
		cursor = 0;
		coluna = 0;
		while(coluna < 4)
		{
			if(cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			coluna++;
		}
		linha++;
		if(visao != 0)
			return(0);
	}
	return(1);
}

int		validate_right_to_left(int matriz[4][4])
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	linha = 3;
	while(linha >= 0)
	{
		visao = matriz[linha][3];
		cursor = 0;
		coluna = 3;

		while(coluna >= 0)
		{
			if (cursor < matriz[linha][coluna])
			{
				visao--;
				cursor = matriz[linha][coluna];
			}
			coluna--;
		}
		linha--;
		if (visao != 0)
			return (0);
	}
	return (1);
}
