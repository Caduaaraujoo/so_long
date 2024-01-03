/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:45:24 by caredua3          #+#    #+#             */
/*   Updated: 2023/10/26 13:28:33 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	index;

	index = 0;
	string = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	while (index < ft_strlen(s))
	{
		string[index] = f(index, s[index]);
		index++;
	}
	return (string);
}
