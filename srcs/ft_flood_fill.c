/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:13:29 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 18:52:59 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game *matrix, int x, int y)
{
	if (matrix->data_fill[x][y] == '1' || matrix->data_fill[x][y] == 'V')
		return ;
	else if (matrix->data_fill[x][y] == 'C')
		matrix->num_of_collect--;
	else if (matrix->data_fill[x][y] == 'E')
		matrix->quant_end_pos--;
	matrix->data_fill[x][y] = 'V';
	ft_flood_fill(matrix, x + 1, y);
	ft_flood_fill(matrix, x - 1, y);
	ft_flood_fill(matrix, x, y + 1);
	ft_flood_fill(matrix, x, y - 1);
}
