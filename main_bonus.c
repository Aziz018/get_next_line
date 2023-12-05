/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkheta <aelkheta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:14:27 by aelkheta          #+#    #+#             */
/*   Updated: 2023/12/05 08:18:39 by aelkheta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line1;
	char	*line2;
	int		fd1;
	int		fd2;

	fd1 = open("README.md", O_RDONLY);
	fd2 = open("example.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
		return (1);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 != NULL && line2 != NULL)
	{
		printf("File 1: %s\n", line1);
		free(line1);
		line1 = get_next_line(fd1);
		printf("File 2: %s\n", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}
	return (0);
}
