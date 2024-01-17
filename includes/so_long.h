/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:21:27 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/17 13:54:38 by caredua3         ###   ########.fr       */
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
	int		columns;
	int		lines;
	char	**data;
};

void	start_matrix_validation(char *map,
			struct s_matrix_validation *matrix_validation);
void	validate_game(struct s_matrix_validation *matrix_validation);
void	message_sucess_or_error(char *message, int fd);
int		init_map(void);

#endif
