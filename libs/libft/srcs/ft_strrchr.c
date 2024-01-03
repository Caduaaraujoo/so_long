/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:29:37 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:18:22 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last;
	size_t	index;

	last = -1;
	index = 0;
	if (c > 255)
		c %= 256;
	if (c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (s[index])
	{
		if (s[index] == c)
			last = index;
		index++;
	}
	if (last >= 0)
		return (&((char *)s)[last]);
	return (NULL);
}
