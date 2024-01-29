/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:06:23 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 16:03:17 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_matrix(struct s_matrix_validation *matrix_validation,
char *message_error_memory, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		free(matrix_validation->data[index]);
		index++;
	}
	free(matrix_validation->data);
	message_sucess_or_error(message_error_memory, 2);
}