/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:30:23 by caredua3          #+#    #+#             */
/*   Updated: 2024/02/01 19:01:02 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_window_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
	{
		mlx_image_to_window(game->image.mlx_ptr, game->image.wall.img, x, y);
		game->num_of_wall++;
	}
	else if (c == 'C')
		mlx_image_to_window(game->image.mlx_ptr, game->image.collect.img, x, y);
	else if (c == 'E')
		mlx_image_to_window(game->image.mlx_ptr, game->image.exit.img, x, y);
}

static void	fill_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (game->data[i][j])
		{
			fill_window_image(game, game->data[i][j], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

static t_draw	image_load(void *mlx, char *path, t_game *game)
{
	t_draw	img;

	img.texture = mlx_load_png(path);
	if (!img.texture)
		clean_matrix(game, "texture failed to load", game->lines, 2);
	img.img = mlx_texture_to_image(mlx, img.texture);
	if (!img.img)
		clean_matrix(game, "image failed to load", game->lines, 2);
	mlx_delete_texture(img.texture);
	return (img);
}

static void	init_images(t_game *game)
{
	game->image.floor = image_load(game->image.mlx_ptr,
			"assets/floor.png", game);
	game->image.wall = image_load(game->image.mlx_ptr,
			"assets/wall.png", game);
	game->image.player = image_load(game->image.mlx_ptr,
			"assets/player.png", game);
	game->image.exit = image_load(game->image.mlx_ptr,
			"assets/exit.png", game);
	game->image.collect = image_load(game->image.mlx_ptr,
			"assets/collect.png", game);
}

void	init_game(t_game *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->image.mlx_ptr = mlx_init(64 * game->columns, 64 * game->lines,
			"so_long", true);
	if (!game->image.mlx_ptr)
		clean_matrix(game, "Error mlx_init", game->lines, 2);
	init_images(game);
	mlx_image_to_window(game->image.mlx_ptr, game->image.floor.img, 64, 64);
	mlx_resize_image(game->image.floor.img, game->columns
		* 64, game->lines * 64);
	fill_window(game);
	mlx_image_to_window(game->image.mlx_ptr, game->image.player.img,
		game->start_pos_y * 64, game->start_pos_x * 64);
}
