/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:30:33 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/31 19:36:52 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_x_up(t_game *game, int x, int y)
{
	if (game->data[x - 1][y] != '1')
	{
		if (game->data[x - 1][y] == '0')
		{
			game->start_pos_x = x - 1;
			game->image.player.img->instances->y -= 64;
		}
	}
}

static void	move_x_down(t_game *game, int x, int y)
{
	if (game->data[x + 1][y] != '1')
	{
		if (game->data[x + 1][y] == '0')
		{
			game->start_pos_x = x + 1;
			game->image.player.img->instances->y += 64;
		}
		else if (game->data[x + 1][y] == 'C')
		{
			game->image.collect.img->instances[y].enabled = false;
			game->start_pos_x = x + 1;
			game->image.player.img->instances->y += 64;
		}
	}
}
static void	move_y_left(t_game *game, int x, int y)
{
	if (game->data[x][y - 1] != '1')
	{
		if (game->data[x][y - 1] == '0')
		{
			game->start_pos_y = y - 1;
			game->image.player.img->instances->x -= 64;
		}
	}
}

static void	move_y_rigth(t_game *game, int x, int y)
{
	if (game->data[x][y + 1] != '1')
	{
		if (game->data[x][y + 1] == '0')
		{
			game->start_pos_y = y + 1;
			game->image.player.img->instances->x += 64;
		}
	}
}

void	hooks(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->image.mlx_ptr);
		clean_matrix(game, "jogo fechado\n" ,game->lines, 1);
	}
	else if ((keydata.key == MLX_KEY_W) && keydata.action == MLX_PRESS)
		move_x_up(game, game->start_pos_x, game->start_pos_y);
	else if ((keydata.key == MLX_KEY_S) && keydata.action == MLX_PRESS)
		move_x_down(game, game->start_pos_x, game->start_pos_y);
	else if ((keydata.key == MLX_KEY_A) && keydata.action == MLX_PRESS)
		move_y_left(game, game->start_pos_x, game->start_pos_y);
	else if ((keydata.key == MLX_KEY_D) && keydata.action == MLX_PRESS)
		move_y_rigth(game, game->start_pos_x, game->start_pos_y);
}