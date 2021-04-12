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

int		validacao_colXup(int matriz[4][4]) 
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	coluna = 0;
	while(coluna < 4)
	{
		visao = matriz[colXup][coluna];
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

int		validacao_colXdown(int matriz[4][4])
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	coluna = 3;
	while(coluna >= 0)
	{
		visao = matriz[colXdown][coluna]
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


int		validacao_rowXleft(int matriz[4][4]) 
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	linha = 0;
	while(linha < 4)
	{
		visao = matriz[rowXleft][linha];
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

int		valicao_rowXleft(int matriz[4][4])
{
	int coluna;
	int linha;
	int visao;
	int cursor;

	linha = 3;
	while(linha >= 0)
	{
		visao = matriz[rowXleft][coluna]
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