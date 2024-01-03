/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:29 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/03 17:31:56 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static union u_return_value	ft_configure_va_arg(char c, va_list args)
{
	union u_return_value	va_type;

	if (c == 's')
	{
		va_type.va_type_str = va_arg(args, char *);
		if (va_type.va_type_str == NULL)
			va_type.va_type_str = "(null)";
	}
	else if (c == 'p')
		va_type.va_type_pointer = va_arg(args, unsigned long);
	else if (c == 'u' || c == 'x' || c == 'X')
		va_type.va_type_unsigned_int = va_arg(args, unsigned int);
	else
		va_type.va_type_int = va_arg(args, int);
	return (va_type);
}

static union u_return_value	ft_verify_type_print(char c, va_list args)
{
	union u_return_value	result;

	if (c != '%')
		result = ft_configure_va_arg(c, args);
	if (c == 'c')
		ft_putchar_fd(result.va_type_int, 1);
	else if (c == 's')
		ft_putstr_fd((char *)result.va_type_str, 1);
	else if (c == 'p')
		result.va_type_str = ft_prefix_hex(result.va_type_pointer);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(result.va_type_int, 1);
	else if (c == 'u')
		ft_putnbr_unsigned(result.va_type_unsigned_int, 1);
	else if (c == 'x' || c == 'X')
		result.va_type_str = ft_convert_dec_hex(result.va_type_unsigned_int, c);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	return (result);
}

static int	ft_length_printf(char type, union u_return_value value_return)
{
	int		len;
	char	*str;

	len = 0;
	if (type == 'c' || type == '%')
		return (1);
	if (type == 'x' || type == 'X' || type == 'p')
	{
		len = ft_strlen(value_return.va_type_str);
		free(value_return.va_type_str);
		return (len);
	}
	if (type != 's')
	{
		if (type == 'u')
			str = ft_itoa_unsigned(value_return.va_type_unsigned_int);
		else
			str = ft_itoa(value_return.va_type_int);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (ft_strlen(value_return.va_type_str));
}

int	ft_printf(const char *value, ...)
{
	int						i;
	int						amount;
	va_list					args;
	union u_return_value	result_return;

	va_start(args, value);
	i = 0;
	amount = 0;
	if (value == NULL)
		return (-1);
	while (value[i])
	{
		if (value[i] == '%')
		{
			result_return = ft_verify_type_print(value[i + 1], args);
			amount += ft_length_printf(value[i + 1], result_return);
			i += 2;
			continue ;
		}
		ft_putchar_fd(value[i], 1);
		amount++;
		i++;
	}
	va_end(args);
	return (amount);
}
