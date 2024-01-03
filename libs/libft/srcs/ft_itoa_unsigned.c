/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:20:42 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/03 17:32:06 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_string(unsigned int n)
{
	int				len;
	unsigned int	y;

	len = 0;
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

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*string;

	string = ft_calloc((ft_len_string(n) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	alloc_char_in_string(string, ft_len_string(n) -1, n);
	return (string);
}
