/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:21:27 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/30 19:07:32 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_draw
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	int				x;
	int				y;
}					t_draw;

typedef struct s_images_game
{
	mlx_t			*mlx_ptr;
	void			*win_ptr;
	t_draw			floor;
	t_draw			wall;
	t_draw			player;
	t_draw			exit;
	t_draw			collect;
}				t_image;

typedef struct s_game_validation
{
	int		start_pos_x;
	int		start_pos_y;
	int		quant_init_pos;
	int		quant_end_pos;
	int		num_of_collect;
	int		columns;
	int		lines;
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

#endif
