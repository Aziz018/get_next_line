/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <aelkheta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:34:56 by aelkheta          #+#    #+#             */
/*   Updated: 2023/12/03 18:18:44 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_rest(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*the_rest;

	i = 0;
	j = 0;
	len = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	++i;
	while (buffer[i + len] && buffer[i + len] != '\0')
		len++;
	the_rest = (char *)malloc(sizeof(char) * (len + 1));
	if (!the_rest)
		return (NULL);
	while (buffer[i])
		the_rest[j++] = buffer[i++];
	the_rest[j] = '\0';
	free(buffer);
	return (the_rest);
}

char	*check_next_line(char *buffer)
{
	int		i;
	char	*i_am_the_line;
	ssize_t	len;

	i = 0;
	len = 0;
	if (!buffer)
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	i_am_the_line = (char *)malloc(sizeof(char) * len + 2);
	if (!i_am_the_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n')
	{
		i_am_the_line[i] = buffer[i];
		i++;
	}
	i_am_the_line[i] = '\n';
	i_am_the_line[++i] = '\0';
	return (i_am_the_line);
}

char	*reach_the_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_SETSIZE)
		return (NULL);
	buffer[fd] = reach_the_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = check_next_line(buffer[fd]);
	buffer[fd] = get_the_rest(buffer[fd]);
	return (line);
}
