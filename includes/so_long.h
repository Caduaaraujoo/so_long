/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:21:27 by caredua3          #+#    #+#             */
/*   Updated: 2024/02/02 19:33:15 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_set_image
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}					t_set_image;

typedef struct s_images_game
{
	mlx_t			*mlx_ptr;
	t_set_image		floor;
	t_set_image		wall;
	t_set_image		player;
	t_set_image		exit;
	t_set_image		collect;
}				t_image;

typedef struct s_game_validation
{
	int		start_pos_x;
	int		start_pos_y;
	int		quant_init_pos;
	int		quant_end_pos;
	int		num_of_collect_fill;
	int		num_of_collect;
	int		num_collect;
	int		num_of_wall;
	int		columns;
	int		lines;
	int		steps;
	char	**data;
	char	**data_fill;
	t_image	image;
}			t_game;

void		start_matrix_validation(char *map, t_game *matrix);
void		validate_game(t_game *game);
void		message_sucess_or_error(char *message, int status);
void		init_game(t_game *game);
void		clean_matrix(t_game *game, char *message_error_memory,
				int size, int status);
void		ft_flood_fill(t_game *matrix, int x, int y);
void		hooks(mlx_key_data_t keydata, t_game *game);
void		fill_window_image(t_game *game, char c, int x, int y);

#endif
