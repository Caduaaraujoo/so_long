/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:02:23 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:02:00 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s_1;
	const unsigned char	*s_2;

	i = 0;
	s_1 = s1;
	s_2 = s2;
	while (i < n)
	{
		if (s_1[i] < s_2[i])
			return (-1);
		if (s_1[i] > s_2[i])
			return (1);
		i++;
	}
	return (0);
}
