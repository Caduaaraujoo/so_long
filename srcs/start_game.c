/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:40 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/15 14:50:56 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(char *map)
{
	int fd;
	char *line;
	char *test;

	test = map;

	// Abra um arquivo para leitura (substitua "file.txt" pelo nome do seu arquivo)
	fd = open(map, O_RDONLY);

	if (fd == -1)
		ft_printf("Error opening file");

	// Leia as linhas usando get_next_line
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("Line read: %s", line);
		free(line);
	}

	// Feche o arquivo após a leitura
	close(fd);
}
