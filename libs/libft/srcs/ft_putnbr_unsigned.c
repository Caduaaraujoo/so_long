/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:58:04 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/03 17:31:52 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned int number, int fd)
{
	char	c_char;

	if (number <= 9)
	{
		c_char = number + '0';
		ft_putchar_fd(c_char, fd);
	}
	else
	{
		c_char = (number % 10) + '0';
		ft_putnbr_unsigned(number / 10, fd);
		ft_putchar_fd(c_char, fd);
	}
}
