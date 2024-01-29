/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:47 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 16:07:33 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_arguments(int argc, char *argv)
{
	if (argc != 2)
		message_sucess_or_error("Error Arguments incorrect", 2);
	if (ft_strlen(argv) >= ft_strlen(".ber") &&
		ft_strncmp(argv + ft_strlen(argv) - ft_strlen(".ber"), ".ber",
		ft_strlen(argv)) != 0)
		message_sucess_or_error("The map does not have a .ber extension", 2);
}

int	main(int argc, char *argv[])
{
	struct s_matrix_validation	matrix_validation;

	matrix_validation.number_of_collectibles = 0;
	matrix_validation.quantity_end_position = 0;
	matrix_validation.quantity_initial_position = 0;
	matrix_validation.columns = 0;
	matrix_validation.lines = 0;
	validate_arguments(argc, argv[1]);
	start_matrix_validation(argv[1], &matrix_validation);
	validate_game(&matrix_validation);
	if (matrix_validation.number_of_collectibles != 0 && matrix_validation.quantity_end_position != 0)
		clean_matrix(&matrix_validation,"impossible game", matrix_validation.lines);
	int i = 0;
	while (i < matrix_validation.lines)
	{
		ft_printf("%s", matrix_validation.data[i]);
		i++;
	}
	clean_matrix(&matrix_validation, "Sucess game", matrix_validation.lines);
	// init_map();
	return (0);
}
