/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:21:27 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/16 14:47:26 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "MLX42/MLX42.h"

# define WIDTH 256
# define HEIGHT 256

struct s_matrix_validation
{
	int		columns;
	int		lines;
	char	**data;
};

int		init_map(void);
void	start_game(char *map);

#endif
