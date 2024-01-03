/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:36:23 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:23:42 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	size_t	size;

	size = ft_strlen(s);
	new_string = (char *)malloc((size + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s, size + 1);
	return (new_string);
}
