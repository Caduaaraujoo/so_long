/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:47 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 16:34:18 by caredua3         ###   ########.fr       */
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
	t_game	game_validation;

	game_validation.num_of_collect = 0;
	game_validation.quant_end_pos = 0;
	game_validation.quant_init_pos = 0;
	game_validation.columns = 0;
	game_validation.lines = 0;
	validate_arguments(argc, argv[1]);
	start_matrix_validation(argv[1], &game_validation);
	validate_game(&game_validation);
	if (game_validation.num_of_collect != 0 && game_validation.quant_end_pos != 0)
		clean_matrix(&game_validation,"impossible game", game_validation.lines);
	int i = 0;
	while (i < game_validation.lines)
	{
		ft_printf("%s", game_validation.data[i]);
		i++;
	}
	clean_matrix(&game_validation, "Sucess game", game_validation.lines);
	// init_map();
	return (0);
}
