/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:12:19 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/03 17:32:01 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prefix_hex(unsigned long hex)
{
	char	*str;
	char	*temp;

	if (hex == 0)
	{
		ft_putstr_fd("(nil)", 1);
		str = ft_strdup("(nil)");
		return (str);
	}
	ft_putstr_fd("0x", 1);
	temp = ft_convert_dec_hex(hex, 'x');
	str = ft_strjoin("0x", temp);
	free(temp);
	return (str);
}
