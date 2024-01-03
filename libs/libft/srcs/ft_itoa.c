/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:00:58 by caredua3          #+#    #+#             */
/*   Updated: 2023/10/27 13:06:49 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_string(int n, int sig)
{
	int	len;
	int	y;

	len = 0;
	if (sig != 1)
		len = 1;
	y = n;
	while (y >= 10)
	{
		len++;
		y /= 10;
	}
	len++;
	return (len);
}

static void	alloc_char_in_string(char *__s, int i, int n)
{
	char	c;

	while (i >= 0)
	{
		c = n % 10 + '0';
		__s[i] = c;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*string;
	int		signal;

	signal = 1;
	if (n == -2147483648)
		return (string = ft_strdup("-2147483648"));
	if (n < 0)
		signal = -1;
	string = ft_calloc((ft_len_string(n * signal, signal) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	alloc_char_in_string(string, ft_len_string(n * signal, signal) - 1, n
		* signal);
	if (n < 0)
		string[0] = '-';
	return (string);
}
