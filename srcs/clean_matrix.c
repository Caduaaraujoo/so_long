/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:06:23 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 18:50:15 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_matrix(t_game *game, char *message_error_memory,
			int size, int status)
{
	int	index;

	index = 0;
	while (index < size)
	{
		free(game->data[index]);
		free(game->data_fill[index]);
		index++;
	}
	free(game->data);
	free(game->data_fill);
	message_sucess_or_error(message_error_memory, status);
}
