/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:43:52 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/03 09:00:06 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	base;

	i = 0;
	signal = 1;
	base = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		signal = 1 - 2 * (nptr[i++] == '-');
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
		base = base * 10 + nptr[i++] - '0';
	return (base * signal);
}
