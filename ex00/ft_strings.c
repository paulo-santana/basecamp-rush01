/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:33:13 by psergio-          #+#    #+#             */
/*   Updated: 2021/04/11 13:18:43 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

void	ft_putstr(char *str)
{
	unsigned int	len;

	len = ft_strlen(str);
	write(1, str, len);
}
