/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:45:28 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 10:41:01 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*vector;
	size_t	bytes;

	bytes = nmemb * size;
	if (!size || bytes / size != nmemb)
		return (malloc(0));
	vector = malloc(nmemb * size);
	if (vector == NULL)
		return (vector);
	ft_bzero(vector, nmemb * size);
	return (vector);
}
