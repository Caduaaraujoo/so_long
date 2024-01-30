/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:47 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/30 18:47:59 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_arguments(int argc, char *argv)
{
	if (argc != 2)
		message_sucess_or_error("Error Arguments incorrect", 2);
	if (ft_strlen(argv) >= ft_strlen(".ber")
		&& ft_strncmp(argv + ft_strlen(argv) - ft_strlen(".ber"), ".ber",
			ft_strlen(argv)) != 0)
		message_sucess_or_error("The map does not have a .ber extension", 2);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	game.num_of_collect = 0;
	game.quant_end_pos = 0;
	game.quant_init_pos = 0;
	game.columns = 0;
	game.lines = 0;
	game.image.mlx_ptr = NULL;
	validate_arguments(argc, argv[1]);
	start_matrix_validation(argv[1], &game);
	validate_game(&game);
	ft_flood_fill(&game, game.start_pos_x, game.start_pos_y);
	if (game.num_of_collect != 0 && game.quant_end_pos != 0)
		clean_matrix(&game, "impossible game", game.lines, 2);
	init_game(&game);
	mlx_loop(game.image.mlx_ptr);
	clean_matrix(&game, "Sucess game", game.lines, 1);
	return (0);
}
