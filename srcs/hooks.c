/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:30:33 by caredua3          #+#    #+#             */
/*   Updated: 2024/02/03 13:04:03 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_is_collectable(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->num_of_collect)
	{
		if ((game->image.collect.img->instances[i].x == x
				&& game->image.collect.img->instances[i].y == y)
			&& game->image.collect.img->instances[i].enabled)
		{
				game->image.collect.img->instances[i].enabled = false;
				game->num_collect--;
		}
		i++;
	}
}

static int	check_is_wall(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->num_of_wall)
	{
		if (game->image.wall.img->instances[i].x == x
			&& game->image.wall.img->instances[i].y == y)
			return (0);
		i++;
	}
	return (1);
}

static void	chack_is_finish(t_game *game, int x, int y)
{
	if (game->image.exit.img->instances[0].x == x
		&& game->image.exit.img->instances[0].y == y && game->num_collect == 0)
		clean_matrix(game, "finish game", game->lines, 1);
}

static void	player_movement(t_game *game, int x, int y)
{
	if (check_is_wall(game, x, y))
	{
		ft_printf("%d\n", game->steps++);
		game->image.player.img->instances[0].x = x;
		game->image.player.img->instances[0].y = y;
	}
	check_is_collectable(game, x, y);
	chack_is_finish(game, x, y);
}

void	hooks(mlx_key_data_t keydata, t_game *game)
{
	int		x;
	int		y;

	y = game->image.player.img->instances[0].y;
	x = game->image.player.img->instances[0].x;
	if (keydata.key == MLX_KEY_ESCAPE)
		clean_matrix(game, "game close\n", game->lines, 1);
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_PRESS)
		player_movement(game, x, y - 64);
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_PRESS)
		player_movement(game, x, y + 64);
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_PRESS)
		player_movement(game, x - 64, y);
	else if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_PRESS)
		player_movement(game, x + 64, y);
}
