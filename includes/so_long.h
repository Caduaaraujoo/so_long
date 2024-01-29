/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:21:27 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 16:34:03 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include "MLX42/MLX42.h"

# define WIDTH 256
# define HEIGHT 256

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
}			t_game;

void	start_matrix_validation(char *map, t_game *matrix);
void	validate_game(t_game *game_validation);
void	message_sucess_or_error(char *message, int fd);
int		init_map(void);
void	clean_matrix(t_game *game_validation, char *message_error_memory, int size);

#endif
