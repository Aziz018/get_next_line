/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <aelkheta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:21:05 by aelkheta          #+#    #+#             */
/*   Updated: 2023/12/03 10:58:15 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_the_rest(char *buffer)
{
    ssize_t i = 0;
    ssize_t j = 0;
    ssize_t len = 0;
    char *the_rest;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    j = i + 1;
    while (buffer[++i] && buffer[i] != '\0')
        len++;
    the_rest = (char *)malloc(sizeof(char) * (len + 1));
    if (!the_rest)
        return NULL;
    ft_strlcpy(the_rest, &buffer[j], len + 1);
    return the_rest;
}

char *check_next_line(char *buffer)
{
    int i;
    char *i_am_the_line;
    ssize_t len_to_next_line;
    
    i = -1;
    len_to_next_line = 0;
    while (buffer[len_to_next_line] != '\n')
        len_to_next_line++;
    i_am_the_line = (char *)malloc(sizeof(char) * len_to_next_line + 2);
    if(!i_am_the_line)
        return NULL;
    while (++i < len_to_next_line)
        i_am_the_line[i] = buffer[i];
    i_am_the_line[i] = '\n';
    i_am_the_line[++i] = '\0';
    return i_am_the_line;
    
}

char *reach_the_line(int fd, ssize_t *bytes_read, char *line, char *buffer)
{
    *bytes_read = read(fd, line, BUFFER_SIZE);
    if(*bytes_read < 0)
    {
        free(buffer);
        free(line);
        return NULL;
    }

    line[*bytes_read] = '\0';
    buffer = ft_strjoin(buffer, line);
    return buffer;
}

char    *get_next_line(int fd)
{
    static char *buffer;
    char *get_line;
    char *next;
    ssize_t bytes_read;
    
    get_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(get_line, '\n'))
    {
        buffer = reach_the_line(fd, &bytes_read, get_line, buffer);
        if(!buffer || bytes_read == 0)
            return NULL;
    }
    next = check_next_line(buffer);
    buffer = get_the_rest(buffer);
    free(get_line);
    return next;
}

int main()
{
    int fd = open("txt.txt", O_RDONLY);
    if (fd < 0)
        return 1;

    char *next_line;

    while ((next_line = get_next_line(fd)) != NULL)
    {
        printf("%s", next_line);
        free(next_line);
    }

    close(fd);
    return 0;
}