/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:47 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:03 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Written by Bruh

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc > 20)
		ft_printf(" Error\n Arguments incorrect");
	else
		start_game(argv[1]);
	return (0);
}
