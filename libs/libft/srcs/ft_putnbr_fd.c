/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:00:37 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:03:08 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_convert_int_for_char(int n, int fd)
{
	char	c_char;

	if (n <= 9)
	{
		c_char = n + '0';
		ft_putchar_fd(c_char, fd);
	}
	else
	{
		c_char = (n % 10) + '0';
		ft_convert_int_for_char(n / 10, fd);
		ft_putchar_fd(c_char, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	signal;

	signal = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		signal = -1;
	}
	ft_convert_int_for_char(n * signal, fd);
}
