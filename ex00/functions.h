/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vribeiro <vribeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 02:37:03 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/12 00:42:03 by vribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

unsigned int	ft_strlen(char *str);
int				is_parameter_valid(char *str);
int				is_board_valid(int board[4][4]);
int				validacao_colXup(int matriz[4][4]);
int				validacao_colXdown(int matriz[4][4]);
int				validacao_rowXleft(int matriz[4][4]); 
int				valicao_rowXleft(int matriz[4][4]);

#endif
