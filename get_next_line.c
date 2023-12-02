/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <aelkheta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:21:05 by aelkheta          #+#    #+#             */
/*   Updated: 2023/12/02 14:43:23 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_next_line(char *buffer)
{
    int i;
    char *i_am_the_line;
    ssize_t len_to_next_line;
    
    i = -1;
    len_to_next_line = 0;
    while (buffer[len_to_next_line] != '\n')
        len_to_next_line++;
    i_am_the_line = (char *)malloc(sizeof(char) * len_to_next_line + 1);
    if(!i_am_the_line)
        return NULL;
    while (++i < len_to_next_line)
        i_am_the_line[i] = buffer[i];
    i_am_the_line[i] = '\n';
    i_am_the_line[i + 1] = '\0';
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
    char *temp;
    ssize_t bytes_read;
    
    get_line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    bytes_read = read(fd, get_line, BUFFER_SIZE);
    while (bytes_read && !ft_strchr(get_line, '\n'))
    {
        buffer = reach_the_line(fd, &bytes_read, get_line, buffer);
        if(!buffer)
            return NULL;
    }
    buffer = check_next_line(buffer);
    return buffer;
}

int main()
{
    int fd;

    fd = open("txt.txt", O_RDONLY);
    if(fd < 0)
        return 1;
    char *next_line;

    next_line = get_next_line(fd);
    printf("%s", next_line);
    next_line = get_next_line(fd);
    printf("%s", next_line);
    free(next_line);
    return 0;
}