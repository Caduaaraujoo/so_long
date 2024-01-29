/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:24 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 16:49:05 by caredua3         ###   ########.fr       */
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

static void	map_is_rectangular(t_game *game_validation)
{
	int	index;

	index = 0;
	while(index < game_validation->lines)
	{
		if (ft_strlen(game_validation->data[index]) != (size_t)game_validation->columns)
			message_sucess_or_error("map is not rectangular", 2);
		index++;
	}
}

static void	map_wall_is_valid(t_game *game_validation)
{
	int	index;
	int	j;

	index = 0;
	while (index < game_validation->lines)
	{
		j = 0;
		if (index == 0 || index == game_validation->lines - 1)
		{
			while (game_validation->data[index][j])
			{
				if (game_validation->data[index][j] != '1')
					clean_matrix(game_validation, "The walls on the map are not correct.", game_validation->lines);
				j++;
			}
		}
		else
		{
			if (game_validation->data[index][0] != '1' || game_validation->data[index][game_validation->columns - 1] != '1')
				clean_matrix(game_validation, "The walls on the map are not correct.", game_validation->lines);
		}
		index++;
	}
}

void static	flood_fill(t_game *matrix, int x, int y)
{
	if (matrix->data[x][y] == '1' || matrix->data[x][y] == 'V')
		return ;
	else if (matrix->data[x][y] == 'C')
		matrix->num_of_collect--;
	else if (matrix->data[x][y] == 'E')
		matrix->quant_end_pos--;
	matrix->data[x][y] = 'V';
	flood_fill(matrix, x + 1, y);
	flood_fill(matrix, x - 1, y);
	flood_fill(matrix, x, y + 1);
	flood_fill(matrix, x, y - 1);
}

void static	character_verification(t_game *game_validation)
{
	int	index;
	int	j;

	index = 0;
	while (index < game_validation->lines)
	{
		j = 0;
		while (game_validation->data[index][j])
		{
			if (!ft_strpbrk(game_validation->data[index], "01CEP"))
				clean_matrix(game_validation, "invalid character", game_validation->lines);
			if (game_validation->data[index][j] =='P')
			{
				game_validation->quant_init_pos++;
				game_validation->start_pos_x = index;
				game_validation->start_pos_y = j;
			}
			if (game_validation->data[index][j] == 'E')
				game_validation->quant_end_pos++;
			if (game_validation->data[index][j] == 'C')
				game_validation->num_of_collect++;
			j++;
		}
		index++;
	}
}

void	validate_game(t_game *game_validation)
{
	character_verification(game_validation);
	if (game_validation->quant_init_pos != 1)
		clean_matrix(game_validation, "incorrect starting position", game_validation->lines);
	if (game_validation->quant_end_pos != 1)
		clean_matrix(game_validation, "incorrect final position", game_validation->lines);
	if (game_validation->num_of_collect == 0)
		clean_matrix(game_validation, "no collectibles in the game", game_validation->lines);
	map_is_rectangular(game_validation);
	map_wall_is_valid(game_validation);
	flood_fill(game_validation, game_validation->start_pos_x, game_validation->start_pos_y);
}
