/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:40 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 16:28:13 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_size_columns_and_lines(char *map, t_game
		*game_validation)
{
	int		fd;
	char	*line;
	char	*s_trim;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		message_sucess_or_error("Error opening the file function, which\
 checks the size of columns and rows.", 2);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		s_trim = ft_strtrim(line, "\n");
		game_validation->columns = (ft_strlen(s_trim));
		free(line);
		free(s_trim);
		game_validation->lines++;
	}
	if (game_validation->lines == 0)
		message_sucess_or_error("empty map", 2);
}

static void	matrix_memory_allocation(t_game
		*game_validation)
{
	int		index;

	index = 0;
	game_validation->data = (char **)ft_calloc(game_validation->lines,
			sizeof(char *));
	if (!game_validation->data)
		message_sucess_or_error("Error in memory allocation of\
 matrix rows.", 2);
}

static void	matrix_values_allocation(char *map,
	t_game *game_validation)
{
	int		fd;
	int		index;
	char	*line;
	char	*s_trim;

	index = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		message_sucess_or_error("Error when opening the file function,\
 which adds the data to the matrix.", 2);
	while (index < game_validation->lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (index == game_validation->lines -1 && ft_strchr(line, '\n'))
			clean_matrix(game_validation,"inadequate line break", game_validation->lines);
		s_trim = ft_strtrim(line, "\n");
		game_validation->data[index] = s_trim;
		free(line);
		index++;
	}
	close (fd);
}

void	start_matrix_validation(char *map,
	t_game *game_validation)
{
	check_size_columns_and_lines(map, game_validation);
	matrix_memory_allocation(game_validation);
	matrix_values_allocation(map, game_validation);
}
