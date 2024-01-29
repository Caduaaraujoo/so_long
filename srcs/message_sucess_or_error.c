/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_sucess_or_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:36:26 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/29 18:50:35 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error(char *message)
{
	ft_putstr_fd("Erro: ", 2);
	ft_putstr_fd(message, 2);
	exit(1);
}

static void	sucess(char *message)
{
	ft_putstr_fd("Sucess: ", 1);
	ft_putstr_fd(message, 1);
	exit(0);
}

void	message_sucess_or_error(char *message, int status)
{
	if (status == 2)
		error(message);
	else
		sucess(message);
}
