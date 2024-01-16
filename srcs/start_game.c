/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:40 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/16 15:10:13 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	matrix_memory_allocation(struct s_matrix_validation *matrix_validation, int lines, int columns)
{
	int		index;

	index = 0;
	matrix_validation->columns = columns / lines;
	matrix_validation->lines = lines;
	matrix_validation->data = (char **)ft_calloc(lines, sizeof(char *));
	if (!matrix_validation->data)
		ft_printf("Erro na alocação");
	while (index < lines)
	{
		matrix_validation->data[index] = (char *)ft_calloc((columns / lines), sizeof(char));
		if (!matrix_validation->data[index])
			ft_printf("Erro na alocação");
		index++;
	}
}

// static int	matrix_check_new_line(char *map, int size_lines)
// {
// 	int		index_line;
// 	char	*line;
// 	int		fd;

// 	fd = open(map, O_RDONLY);
// 	index_line = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		if (index_line == 0 && ft_strchr(line, '\n') != NULL && ft_strlen(line) >= 1)
// 			return (0);
// 		else if (index_line != size_lines && ft_strchr(line, '\n') != NULL)
// 			return (0);
// 		index_line++;
// 		free(line);
// 	}
// 	close (fd);
// 	return (1);
// }

static void	matrix_values_allocation(char *map, struct s_matrix_validation *matrix_validation, int lines)
{
	int		fd;
	int		index;
	char	*line;

	index = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_printf("Error opening file");
	while (index < lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		matrix_validation->data[index] = ft_strdup(line);
		free(line);
		index++;
	}
	close (fd);
}

void	start_game(char *map)
{
	int		fd;
	char	*line;
	int		size_lines;
	int		size_columns;
	struct	s_matrix_validation matrix_validation;

	size_lines = 0;
	size_columns = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_printf("Error opening file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		size_columns += (ft_strlen(line));
		free(line);
		size_lines++;
	}
	matrix_memory_allocation(&matrix_validation, size_lines, size_columns);
	matrix_values_allocation(map, &matrix_validation, size_lines);
	// ft_printf("Quebra de linha em local indevido");
	int i = 0;
	while (i < matrix_validation.lines)
	{
		ft_printf("%s", matrix_validation.data[i]);
		i++;
	}
	close(fd);
}