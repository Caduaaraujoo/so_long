/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:24 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 18:52:17 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strpbrk(const char *str1, const char *str2)
{
	int	index;
	int	j;

	index = 0;
	while (str1[index])
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

static void	map_is_rectangular(t_game *game)
{
	int	index;

	index = 0;
	while (index < game->lines)
	{
		if (ft_strlen(game->data[index])
			!= (size_t)game->columns)
			message_sucess_or_error("map is not rectangular", 2);
		index++;
	}
}

static void	map_wall_is_valid(t_game *game)
{
	int	index;
	int	j;

	index = 0;
	while (index < game->lines)
	{
		j = 0;
		if (index == 0 || index == game->lines - 1)
		{
			while (game->data[index][j])
			{
				if (game->data[index][j++] != '1')
					clean_matrix(game, "The walls on the map are not correct.",
						game->lines, 2);
			}
		}
		else
		{
			if (game->data[index][0] != '1'
				|| game->data[index][game->columns - 1] != '1')
				clean_matrix(game, "The walls on the map are not correct.",
					game->lines, 2);
		}
		index++;
	}
}

void static	character_verification(t_game *game)
{
	int	index;
	int	j;

	index = 0;
	while (index < game->lines)
	{
		j = 0;
		while (game->data[index][j])
		{
			if (!ft_strpbrk(game->data[index], "01CEP"))
				clean_matrix(game, "invalid character", game->lines, 2);
			if (game->data[index][j] == 'P')
			{
				game->quant_init_pos++;
				game->start_pos_x = index;
				game->start_pos_y = j;
			}
			if (game->data[index][j] == 'E')
				game->quant_end_pos++;
			if (game->data[index][j] == 'C')
				game->num_of_collect++;
			j++;
		}
		index++;
	}
}

void	validate_game(t_game *game)
{
	character_verification(game);
	if (game->quant_init_pos != 1)
		clean_matrix(game, "incorrect starting position",
			game->lines, 2);
	if (game->quant_end_pos != 1)
		clean_matrix(game, "incorrect final position",
			game->lines, 2);
	if (game->num_of_collect == 0)
		clean_matrix(game, "no collectibles in the game",
			game->lines, 2);
	map_is_rectangular(game);
	map_wall_is_valid(game);
}
