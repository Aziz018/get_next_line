/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <aelkheta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:21:38 by aelkheta          #+#    #+#             */
/*   Updated: 2023/12/02 11:52:16 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42

#endif

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char    *get_next_line(int fd);

#endif