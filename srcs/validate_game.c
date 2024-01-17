/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:24 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/17 14:56:03 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_is_rectangular(struct s_matrix_validation *matrix_validation)
{
	int	index;

	index = 0;
	while(index < matrix_validation->lines)
	{
		if ((index == 0 && ft_strlen(matrix_validation->data[index]) != 1)
		&& (ft_strlen(matrix_validation->data[index]) != (size_t)matrix_validation->columns))
			message_sucess_or_error("Não é retangulo 1", 2);
		if (ft_strlen(matrix_validation->data[index]) != (size_t)matrix_validation->columns)
			message_sucess_or_error("Não é retangulo 2", 2);
		index++;
	}
}

void	validate_game(struct s_matrix_validation *matrix_validation)
{
	map_is_rectangular(matrix_validation);
}