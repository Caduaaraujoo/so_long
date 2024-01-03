/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_dec_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:57:42 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/03 17:32:10 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assembly_hex(t_list *l_rest, char x)
{
	int		i;
	int		content_list;
	char	*digits_hex;
	char	*str;
	t_list	*current;

	digits_hex = ft_strdup("0123456789abcdef");
	str = ft_calloc(ft_lstsize(l_rest) + 1, sizeof(char));
	current = l_rest;
	i = 0;
	while (current)
	{
		content_list = *((int *)current->content);
		if (x == 'X' && (digits_hex[content_list] >= 'a'
				&& digits_hex[content_list] <= 'f'))
			str[i] = (digits_hex[content_list] - 32);
		else
			str[i] = digits_hex[content_list];
		current = current->next;
		i++;
	}
	free(digits_hex);
	return (str);
}

char	*ft_convert_dec_hex(unsigned long n, char x)
{
	unsigned long	divider;
	t_list			*l_rest;
	t_list			*new_node;
	char			*str_hex;

	divider = -1;
	l_rest = NULL;
	while (divider != 0)
	{
		divider = n / 16;
		new_node = ft_lstnew(ft_calloc(1, sizeof(int)));
		*(int *)new_node->content = n % 16;
		ft_lstadd_front(&l_rest, new_node);
		n = divider;
	}
	str_hex = ft_assembly_hex(l_rest, x);
	ft_lstclear(&l_rest, free);
	ft_putstr_fd(str_hex, 1);
	return (str_hex);
}
