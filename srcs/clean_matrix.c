/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:06:23 by caredua3          #+#    #+#             */
/*   Updated: 2024/02/03 13:11:36 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_matrix(t_game *game, char *message_error_memory, int size,
		int status)
{
	int	index;

	index = 0;
	if (game == NULL || game->data == NULL || game->data_fill == NULL)
		message_sucess_or_error("matrix does not exist", 2);
	while (index < size)
	{
		if (game->data[index] != NULL)
		{
			free(game->data[index]);
			game->data[index] = NULL;
		}
		if (game->data_fill[index] != NULL)
		{
			free(game->data_fill[index]);
			game->data_fill[index] = NULL;
		}
		index++;
	}
	free(game->data);
	free(game->data_fill);
	if (game->image.mlx_ptr)
		mlx_terminate(game->image.mlx_ptr);
	message_sucess_or_error(message_error_memory, status);
}
