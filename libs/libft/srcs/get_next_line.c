/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caredua3 <caredua3@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:39:34 by caredua3          #+#    #+#             */
/*   Updated: 2023/11/18 16:47:29 by caredua3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_adjust_list_head(t_list **l_gnl)
{
	t_list	*temp;

	while (*l_gnl && (*l_gnl)->content != '\n')
	{
		temp = *l_gnl;
		*l_gnl = (*l_gnl)->next;
		free(temp);
	}
	if (*l_gnl && (*l_gnl)->content == '\n')
	{
		temp = *l_gnl;
		*l_gnl = (*l_gnl)->next;
		free(temp);
	}
}

static int	ft_form_setence_from_list(t_list **l_gnl, char **string_read,
		int bytes)
{
	t_list	*current;
	int		index;

	current = *l_gnl;
	index = 0;
	*string_read = ft_calloc((ft_lstsize_or_size_newline(*l_gnl) + 1),
			sizeof(char));
	while (current)
	{
		if (current->content == '\n')
		{
			(*string_read)[index] = current->content;
			if (current->next && current->next->content)
				ft_adjust_list_head(l_gnl);
			else
				ft_lstclear(l_gnl);
			return (1);
		}
		(*string_read)[index] = current->content;
		index++;
		current = current->next;
	}
	if (bytes == 0)
		ft_lstclear(l_gnl);
	return (0);
}

static char	*ft_read_fd(int fd, t_list **l_gnl, char **string_read)
{
	char	*buffer;
	int		bytes_read;
	int		i;
	int		is_finish;

	i = 0;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	is_finish = 0;
	if (bytes_read == -1 || (bytes_read == 0 && (*l_gnl) == NULL))
	{
		ft_lstclear(l_gnl);
		free(buffer);
		return (NULL);
	}
	while (buffer[i])
		ft_lstadd_back(l_gnl, ft_lstnew(buffer[i++]));
	is_finish = ft_form_setence_from_list(l_gnl, string_read, bytes_read);
	free(buffer);
	if (bytes_read > 0 && is_finish == 0)
	{
		free(*string_read);
		return (NULL);
	}
	return (*string_read);
}

char	*get_next_line(int fd)
{
	char			*string;
	static t_list	*l_gnl;

	string = NULL;
	if (fd == -1)
		return (NULL);
	if (BUFFER_SIZE > 0)
	{
		string = ft_read_fd(fd, &l_gnl, &string);
		while (string == NULL && l_gnl != NULL)
			string = ft_read_fd(fd, &l_gnl, &string);
	}
	return (string);
}
