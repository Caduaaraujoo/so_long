/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:24 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/24 19:01:21 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strpbrk(const char *str1, const char *str2)
{
	int	index;
	int	j;

	index = 0;
	while(str1[index])
	{
		j = 0;
		while (str2[j])
		{
			if (ft_strchr(str2, str1[index]))
				j++;
			else
				return (0);
		}
		index++;
	}
	return (1);
}

static void	map_is_rectangular(struct s_matrix_validation *matrix_validation)
{
	int	index;

	index = 0;
	while(index < matrix_validation->lines)
	{
		if (ft_strlen(matrix_validation->data[index]) != (size_t)matrix_validation->columns)
			message_sucess_or_error("map is not rectangular", 2);
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

void static	flood_fill(struct s_matrix_validation *matrix, int x, int y)
{
	if (matrix->data[x][y] == '1' || matrix->data[x][y] == 'V')
		return ;
	else if (matrix->data[x][y] == 'C')
		matrix->number_of_collectibles--;
	else if (matrix->data[x][y] == 'E')
		matrix->quantity_end_position--;
	matrix->data[x][y] = 'V';
	flood_fill(matrix, x + 1, y);
	flood_fill(matrix, x - 1, y);
	flood_fill(matrix, x, y + 1);
	flood_fill(matrix, x, y - 1);
}

void static	character_verification(struct s_matrix_validation *matrix_validation)
{
	int	index;
	int	j;

	index = 0;
	while (index < matrix_validation->lines)
	{
		j = 0;
		while (matrix_validation->data[index][j])
		{
			if (!ft_strpbrk(matrix_validation->data[index], "01CEP"))
				clean_matrix(matrix_validation, "invalid character", matrix_validation->lines);
			if (matrix_validation->data[index][j] =='P')
			{
				matrix_validation->quantity_initial_position++;
				matrix_validation->starting_position_x = index;
				matrix_validation->starting_position_y = j;
			}
			if (matrix_validation->data[index][j] == 'E')
				matrix_validation->quantity_end_position++;
			if (matrix_validation->data[index][j] == 'C')
				matrix_validation->number_of_collectibles++;
			j++;
		}
		index++;
	}
}

void	validate_game(struct s_matrix_validation *matrix_validation)
{
	character_verification(matrix_validation);
	if (matrix_validation->quantity_initial_position != 1)
		clean_matrix(matrix_validation, "incorrect starting position", matrix_validation->lines);
	if (matrix_validation->quantity_end_position != 1)
		clean_matrix(matrix_validation, "incorrect final position", matrix_validation->lines);
	if (matrix_validation->number_of_collectibles == 0)
		clean_matrix(matrix_validation, "no collectibles in the game", matrix_validation->lines);
	map_is_rectangular(matrix_validation);
	map_wall_is_valid(matrix_validation);
	flood_fill(matrix_validation, matrix_validation->starting_position_x, matrix_validation->starting_position_y);
}
