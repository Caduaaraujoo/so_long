/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:39:20 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:03:53 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (c > 255)
		c %= 256;
	if (c == '\0')
	{
		len = ft_strlen(s);
		return (&((char *)s)[len]);
	}
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
