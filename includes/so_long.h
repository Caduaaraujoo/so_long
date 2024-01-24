/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:21:27 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/24 17:00:07 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include <stdio.h>
# include "MLX42/MLX42.h"

# define WIDTH 256
# define HEIGHT 256

struct s_matrix_validation
{
	int		starting_position_x;
	int		starting_position_y;
	int		quantity_initial_position;
	int		quantity_end_position;
	int		number_of_collectibles;
	int		columns;
	int		lines;
	char	**data;
};

void	start_matrix_validation(char *map,
			struct s_matrix_validation *matrix_validation);
void	validate_game(struct s_matrix_validation *matrix_validation);
void	message_sucess_or_error(char *message, int fd);
int		init_map(void);
void	clean_matrix(struct s_matrix_validation *matrix_validation,
			char *message_error_memory, int size);

#endif
