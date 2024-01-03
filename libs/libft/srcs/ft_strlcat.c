/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:52:59 by caredua3          #+#    #+#             */
/*   Updated: 2023/10/18 17:26:00 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	amount_dst;
	size_t	amount_src;
	size_t	amount_total;

	i = 0;
	amount_dst = ft_strlen(dst);
	amount_src = ft_strlen(src);
	amount_total = amount_dst + amount_src;
	if (size <= amount_dst)
		return (size + amount_src);
	while (src[i] != '\0' && amount_dst < size - 1)
	{
		dst[amount_dst] = src[i];
		amount_dst++;
		i++;
	}
	dst[amount_dst] = '\0';
	return (amount_total);
}
