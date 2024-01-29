/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:40 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 18:51:46 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_size_columns_and_lines(char *map, t_game *game)
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
		game->columns = (ft_strlen(s_trim));
		free(line);
		free(s_trim);
		game->lines++;
	}
	if (game->lines == 0)
		message_sucess_or_error("empty map", 2);
}

static void	matrix_memory_allocation(t_game *game)
{
	int	index;

	index = 0;
	game->data = (char **)ft_calloc(game->lines,
			sizeof(char *));
	game->data_fill = (char **)ft_calloc(game->lines,
			sizeof(char *));
	if (!game->data || !game->data_fill)
		message_sucess_or_error("Error in memory allocation of\
 matrix rows.", 2);
}

static void	matrix_values_allocation(char *map, t_game *game)
{
	int		fd;
	int		index;
	char	*line;
	char	*s_trim;
	char	*s_trim_fill;

	index = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		message_sucess_or_error("Error when opening the file function", 2);
	while (index < game->lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (index == game->lines - 1 && ft_strchr(line, '\n'))
			clean_matrix(game, "inadequate line break", game->lines, 2);
		s_trim = ft_strtrim(line, "\n");
		s_trim_fill = ft_strtrim(line, "\n");
		game->data[index] = s_trim;
		game->data_fill[index] = s_trim_fill;
		free(line);
		index++;
	}
	close(fd);
}

void	start_matrix_validation(char *map, t_game *game)
{
	check_size_columns_and_lines(map, game);
	matrix_memory_allocation(game);
	matrix_values_allocation(map, game);
}
