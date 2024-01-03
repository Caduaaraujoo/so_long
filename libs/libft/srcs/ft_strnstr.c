/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:56:29 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:05:01 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (ft_strlen(little) > ft_strlen(big))
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && ft_strncmp(&big[i + j], &little[j], 1) == 0)
			j++;
		if (little[j] == '\0' && (j + i) <= len)
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
