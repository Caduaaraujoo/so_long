/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_matrix_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:25:40 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/24 19:00:42 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_size_columns_and_lines(char *map, struct s_matrix_validation
		*matrix_validation)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		message_sucess_or_error("Error opening the file function, which\
 checks the size of columns and rows.", 2);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line = ft_strtrim(line, "\n");
		matrix_validation->columns = (ft_strlen(line));
		free(line);
		matrix_validation->lines++;
	}
	if (matrix_validation->lines == 0)
		message_sucess_or_error("empty map", 2);
}

static void	matrix_memory_allocation(struct s_matrix_validation
		*matrix_validation)
{
	int		index;

	index = 0;
	matrix_validation->data = (char **)ft_calloc(matrix_validation->lines,
			sizeof(char *));
	if (!matrix_validation->data)
		message_sucess_or_error("Error in memory allocation of\
 matrix rows.", 2);
	while (index < matrix_validation->lines)
	{
		matrix_validation->data[index] = (char *)ft_calloc(
				(matrix_validation->columns / matrix_validation->lines),
				sizeof(char));
		if (!matrix_validation->data[index])
			clean_matrix(matrix_validation, "Error in memory allocation of\
 matrix columns", index + 1);
		index++;
	}
}

static void	matrix_values_allocation(char *map,
	struct s_matrix_validation *matrix_validation)
{
	int		fd;
	int		index;
	char	*line;

	index = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		message_sucess_or_error("Error when opening the file function,\
 which adds the data to the matrix.", 2);
	while (index < matrix_validation->lines)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (index == matrix_validation->lines -1 && ft_strchr(line, '\n'))
			clean_matrix(matrix_validation,"inadequate line break", matrix_validation->lines);
		line = ft_strtrim(line, "\n");
		matrix_validation->data[index] = ft_strdup(line);
		free(line);
		index++;
	}
	close (fd);
}

void	start_matrix_validation(char *map,
	struct s_matrix_validation *matrix_validation)
{
	check_size_columns_and_lines(map, matrix_validation);
	matrix_memory_allocation(matrix_validation);
	matrix_values_allocation(map, matrix_validation);
}
