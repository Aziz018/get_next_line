#include "get_next_line.h"
#include "get_next_line_bonus.h"



int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("get_next_line.c", O_RDONLY);
	if (fd < 0)
		return (1);
	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
