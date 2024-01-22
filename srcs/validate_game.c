/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:24 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/22 16:41:08 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_is_rectangular(struct s_matrix_validation *matrix_validation)
{
	int	index;

	index = 0;
	while(index < matrix_validation->lines)
	{
		if (ft_strlen(matrix_validation->data[index]) != (size_t)matrix_validation->columns)
			message_sucess_or_error("Não é retangulo 1", 2);
		index++;
	}
}

static void	map_wall_is_valid(struct s_matrix_validation *matrix_validation)
{
	int	index;
	int	j;

	index = 0;
	while (index < matrix_validation->lines)
	{
		j = 0;
		if (index == 0 || index == matrix_validation->lines - 1)
		{
			while (matrix_validation->data[index][j])
			{
				if (matrix_validation->data[index][j] != '1')
					clean_matrix(matrix_validation, "The walls on the map are not correct.", matrix_validation->lines);
				j++;
			}
		}
		else
		{
			if (matrix_validation->data[index][0] != '1' || matrix_validation->data[index][matrix_validation->columns - 1] != '1')
				clean_matrix(matrix_validation, "The walls on the map are not correct.", matrix_validation->lines);
		}
		index++;
	}
}

static void	game_characters(struct s_matrix_validation *matrix_validation)
{
	int	index;
	int j;
	int	quantity_initial_position;
	int	quantity_end_position;
	int	number_of_collectibles;

	quantity_initial_position = 0;
	quantity_end_position = 0;
	number_of_collectibles = 0;
	index = 0;
	while(index < matrix_validation->lines)
	{
		j = 0;
		while (matrix_validation->data[index][j])
		{
			if (ft_strchr(matrix_validation->data[index][j], 'P') != NULL)
				quantity_initial_position++;
			else if (ft_strchr(matrix_validation->data[index][j], 'E') != NULL)
				quantity_end_position++;
			else if (ft_strchr(matrix_validation->data[index][j], 'C') != NULL)
				number_of_collectibles++;
			j++;
		}
		index++;
	}
}

void	validate_game(struct s_matrix_validation *matrix_validation)
{
	map_is_rectangular(matrix_validation);
	map_wall_is_valid(matrix_validation);
	game_characters(matrix_validation);
}
