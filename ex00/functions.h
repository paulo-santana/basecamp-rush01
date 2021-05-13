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
int				validate_top_to_bottom(int matriz[4][4], int col_up[4]);
int				validate_bottom_to_top(int matriz[4][4], int col_down[4]);
int				validate_left_to_right(int matriz[4][4], int row_left[4]);
int				validate_right_to_left(int matriz[4][4], int row_right[4]);
int				is_solved(int board[4][4], int views[4][4]);
int				find_next(int board[4][4]);
int				solve(int outer_matrix[4][4]);
void			print_matrix(int matrix[4][4]);
int				can_place(int board[4][4], int number, int linha, int coluna);
void			ft_putstr(char *str);
void			ft_puterr(char *str);

#endif
