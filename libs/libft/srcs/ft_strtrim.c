/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:39:51 by caredua3          #+#    #+#             */
/*   Updated: 2023/10/24 20:26:25 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*new_string;
	size_t		len_trim;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (*start && ft_strchr(set, *start) != NULL)
		start++;
	while (end > start && ft_strchr(set, *end) != NULL)
		end--;
	len_trim = end - start + 1;
	new_string = (char *)malloc(len_trim + 1);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, start, ++len_trim);
	return (new_string);
}
