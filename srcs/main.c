/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:47 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/17 13:55:59 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	struct s_matrix_validation	matrix_validation;

	if (argc != 2)
		message_sucess_or_error("Error Arguments incorrect", 2);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		message_sucess_or_error("The map does not have a .ber extension", 2);
	start_matrix_validation(argv[1], &matrix_validation);
	validate_game(&matrix_validation);
	return (0);
}
