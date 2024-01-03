/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:57:32 by caredua3          #+#    #+#             */
/*   Updated: 2024/01/03 18:35:19 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*vector;
	size_t	bytes;
	size_t	i;

	i = 0;
	bytes = nmemb * size;
	if (!size || bytes / size != nmemb)
		return (malloc(0));
	vector = malloc(nmemb * size);
	if (vector == NULL)
		return (vector);
	while (i < bytes)
	{
		((unsigned char *)vector)[i] = '\0';
		i++;
	}
	return (vector);
}

t_list_gnl	*ft_lstnew_gnl(char character)
{
	t_list_gnl	*new_list;

	new_list = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (new_list == NULL)
		return (NULL);
	new_list->content = character;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (!current)
	{
		*lst = new;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = new;
}

int	ft_lstsize_or_size_newline(t_list_gnl *lst)
{
	int		size;
	t_list_gnl	*current;

	size = 0;
	current = lst;
	while (current)
	{
		if (current->content == '\n')
			return (size + 1);
		current = current->next;
		size++;
	}
	return (size);
}

void	ft_lstclear_gnl(t_list_gnl **lst)
{
	t_list_gnl	*current;
	t_list_gnl	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->content = 0;
		free(current);
		current = next;
	}
	*lst = NULL;
}
